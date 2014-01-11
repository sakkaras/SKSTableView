/*
 * Copyright 2012 Inomera Research
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "NMRichPushViewController.h"
#import "NMPushInboxViewController.h"

@interface NMRichPushViewController ()
//This property is used for managing popup animation.
@property (nonatomic, assign) BOOL animationFinished;
@property (nonatomic, strong) IBOutlet UIButton *button;
@property (nonatomic, assign) BOOL shouldShowUnsupportedURLError;

@end

@implementation NMRichPushViewController

-(id)initWithRichPushObject:(NMRichPushObject*)obj
{
    self = [super initWithRichPushObject:obj];
    if (self) {
        self.animationFinished = NO;
        self.shouldShowUnsupportedURLError = NO;
    }
    return self;
}

#pragma mark - actions

-(void)doneButtonTouched
{
    [self dismissViewControllerAnimated:YES completion:^{
    }];
}

- (void)updateWithRichPushObject:(NMRichPushObject*)newObject
{
    [super updateWithRichPushObject:newObject];
    
    UIActivityIndicatorView *activityIndicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhite];
    UIBarButtonItem *indicatorBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:activityIndicator];
    [activityIndicator startAnimating];
    self.navigationItem.rightBarButtonItem = indicatorBarButtonItem;
    
    self.shouldInsertJS = YES;
    self.richPush = newObject;
    self.navigationItem.title = self.richPush.alertText;
    
    BOOL shouldShowUnsupportedURLError = NO;
    
    if (self.richPush.type == NotificationTypeRich || self.richPush.type == NotificationTypePopup) {
        [self.webView loadHTMLString:self.richPush.htmlBody baseURL:nil];
    } else if (self.richPush.type == NotificationTypeURLPush) {
        NSURL *url = [NSURL URLWithString:self.richPush.urlString];
        if (url)
            [self.webView loadRequest:[NSURLRequest requestWithURL:url]];
        else {
            shouldShowUnsupportedURLError = YES;
        }
    }
    
    if ([NMPushManager loadingHUD])
        [[NMPushManager loadingHUD] hide:YES];
    
    if (shouldShowUnsupportedURLError) {
        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:nil
                                                            message:@"Not supported URL for rich push notification"
                                                           delegate:nil
                                                  cancelButtonTitle:@"OK"
                                                  otherButtonTitles:nil];
        [alertView show];
    }
    
    RichPushCompletionHandler handler = [NMPushManager richPushCompletionHandler];
    if (handler)
        handler(nil);
}

-(void)upDownBarButtonTouched:(id)sender
{
    UISegmentedControl *control = (UISegmentedControl*)sender;
    if(control.selectedSegmentIndex == 0)
    {
        NMRichPushObject *newObject = [[NMPushInboxList sharedList] richPushObjectBeforeObject:self.richPush];
        if(newObject)
        {
            [self updateWithRichPushObject:newObject];
        }
    }
    else
    {
        NMRichPushObject *newObject = [[NMPushInboxList sharedList] richPushObjectAfterObject:self.richPush];
        if(newObject)
        {
            [self updateWithRichPushObject:newObject];
        }
    }
}

- (void)webViewDidStartLoad:(UIWebView *)webView
{
    //You should NOT remove this line in order to make controller work properly!!
    [super webViewDidStartLoad:webView];
}

- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType
{
    //You should NOT remove this line in order to make controller work properly!!
    return [super webView:webView shouldStartLoadWithRequest:request navigationType:navigationType];
}

-(void)webViewDidFinishLoad:(UIWebView *)webView
{
    //You should NOT remove this line in order to make controller work properly!!
    [super webViewDidFinishLoad:webView];
    
    if([self.richPush isKindOfClass:[NMPopupObject class]])
    {
        if (webView.loading == NO) {
            if(!self.animationFinished)
            {
                self.animationFinished  = YES;
                //Do popup animation
                self.view.hidden = NO;
                [UIView animateWithDuration:0.4f animations:^{
                    self.view.backgroundColor = [UIColor colorWithWhite:0.5 alpha:0.7];
                }];
                CAKeyframeAnimation *anim = [CAKeyframeAnimation animationWithKeyPath:@"transform.scale"];
                anim.values = @[@0.0f,@1.3f,@0.9f,@1.0f];
                anim.removedOnCompletion = NO;
                anim.duration = 0.8f;
                anim.fillMode = kCAFillModeForwards;
                anim.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];
                [self.webView.layer addAnimation:anim forKey:@"PopAnim"];
            }
        }
    } else {
        if (!webView.loading) {
            if ([Netmera pushInboxEnabled] && self.richPush.shouldShownInInbox) {
                // For up and down push navigation bar button
                UISegmentedControl *upDownControl = [[UISegmentedControl alloc] initWithItems:[[NSArray alloc] initWithObjects:@"\u25B2", @"\u25BC", nil]];
                upDownControl.momentary = YES;
                upDownControl.segmentedControlStyle = UISegmentedControlStyleBar;
                [upDownControl addTarget:self action:@selector(upDownBarButtonTouched:) forControlEvents:UIControlEventValueChanged];
                UIBarButtonItem *upDownBarButton = [[UIBarButtonItem alloc] initWithCustomView:upDownControl];
                [self.navigationItem setRightBarButtonItem:upDownBarButton animated:YES];
                CGRect frame = self.navigationItem.rightBarButtonItem.customView.frame;
                frame.size.width = 100;
                self.navigationItem.rightBarButtonItem.customView.frame = frame;
            }
            else
            {
                self.navigationItem.rightBarButtonItem = nil;
            }
        }
    }
}

- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error
{
    if ([self.richPush isKindOfClass:[NMPopupObject class]]) {
        if (error.code != NSURLErrorCancelled) {
            [self.view removeFromSuperview];
            [self removeFromParentViewController];
        }
    }
}

- (void)closeButtonTouched
{
    if([self.richPush isKindOfClass:[NMPopupObject class]])
    {
        __block NMRichPushViewController *tempController = self;
        [self willMoveToParentViewController:nil];
        [CATransaction begin];
        [CATransaction setCompletionBlock:^{
            [tempController.view removeFromSuperview];            // 2
            [tempController removeFromParentViewController];      // 3
        }];
        
        [UIView animateWithDuration:0.4f animations:^{
            self.view.backgroundColor = [UIColor clearColor];
        }];
        
        CABasicAnimation *anim = [CABasicAnimation animationWithKeyPath:@"transform.scale"];
        anim.toValue = [NSNumber numberWithFloat:0.0f];
        anim.removedOnCompletion = NO;
        anim.duration = 0.6f;
        anim.fillMode = kCAFillModeForwards;
        anim.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];
        [self.webView.layer addAnimation:anim forKey:@"PopAnim"];
        [CATransaction commit];
    }
    else
    {
        [self dismissViewControllerAnimated:YES completion:^{
            [NMPushManager clearRichPush];
        }];
    }
}

#pragma mark - view lifecycle

const CGFloat CloseButtonWidth = 23;

- (void)viewDidLoad
{
    [super viewDidLoad];

    UIWebView *awebview = [[UIWebView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height)];
    awebview.autoresizingMask = UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleWidth;
    awebview.backgroundColor = [UIColor whiteColor];
    self.webView = awebview;
    self.webView.delegate = self;
    
    if (self.richPush.type == NotificationTypeRich || self.richPush.type == NotificationTypePopup) {
        [self.webView loadHTMLString:self.richPush.htmlBody baseURL:nil];
    } else if (self.richPush.type == NotificationTypeURLPush) {
        NSURL *url = [NSURL URLWithString:self.richPush.urlString];
        
        if (url)
            [self.webView loadRequest:[NSURLRequest requestWithURL:url]];
        else
            self.shouldShowUnsupportedURLError = YES;
    }
    
    [self.view addSubview:self.webView];
    
    if([self.richPush isKindOfClass:[NMPopupObject class]])
    {
        self.view.hidden = YES;
    }
    
    self.navigationItem.title = self.richPush.alertText;
    if(![self.richPush isKindOfClass:[NMPopupObject class]])
    {
        UIActivityIndicatorView *activityIndicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhite];
        UIBarButtonItem *indicatorBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:activityIndicator];
        [activityIndicator startAnimating];
        self.navigationItem.rightBarButtonItem = indicatorBarButtonItem;
        
        if (![Netmera pushInboxEnabled] || ([Netmera pushInboxEnabled] && !self.richPush.shouldShownInInbox))
            self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"Close" style:UIBarButtonItemStyleBordered target:self action:@selector(closeButtonTouched)];
    }
    else
    {
        self.webView.frame = CGRectMake(0, 0, self.view.frame.size.width * 0.8f, self.view.frame.size.height * 0.7f);
        self.webView.center = CGPointMake(self.view.bounds.size.width / 2.0, self.view.bounds.size.height / 2.0);
        self.webView.layer.borderWidth = 2.0f;
        self.webView.layer.borderColor = [[UIColor darkGrayColor] CGColor];
        self.webView.layer.cornerRadius = 10.0f;
        self.webView.clipsToBounds = YES;
        
        self.button = [[UIButton alloc] initWithFrame:CGRectMake(self.webView.bounds.size.width - CloseButtonWidth * 1.5f, self.webView.bounds.origin.y + CloseButtonWidth * 0.5f, CloseButtonWidth, CloseButtonWidth)];
        self.button.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleBottomMargin;
        [self.button setBackgroundImage:[UIImage imageNamed:@"popupClose"] forState:UIControlStateNormal];
        [self.button addTarget:self action:@selector(closeButtonTouched) forControlEvents:UIControlEventTouchUpInside];
        self.button.showsTouchWhenHighlighted = YES;
        [self.webView addSubview:self.button];
    }
}

- (void)viewDidAppear:(BOOL)animated
{
    if (self.shouldShowUnsupportedURLError) {
        UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:nil
                                                            message:@"Not supported URL for rich push notification."
                                                           delegate:nil
                                                  cancelButtonTitle:@"OK"
                                                  otherButtonTitles:nil];
        [alertView show];
        
        self.shouldShowUnsupportedURLError = NO;
    }
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Do any additional setup after loading the view from its nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
