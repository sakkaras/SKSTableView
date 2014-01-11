//
//  UIAlertView+MKBlockAdditions.h
//  UIKitCategoryAdditions
//
//  Created by Mugunth on 21/03/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NMBlockAdditions.h"

@interface UIAlertView (NMBlock) <UIAlertViewDelegate>
+ (UIAlertView*) alertViewWithTitle:(NSString*) title 
                            message:(NSString*) message;

+ (UIAlertView*) alertViewWithTitle:(NSString*) title 
                            message:(NSString*) message
                  cancelButtonTitle:(NSString*) cancelButtonTitle;

+ (UIAlertView*) alertViewWithTitle:(NSString*) title                    
                            message:(NSString*) message 
                  cancelButtonTitle:(NSString*) cancelButtonTitle
                  otherButtonTitles:(NSArray*) otherButtons
                          onDismiss:(DismissBlock) dismissed                   
                           onCancel:(CancelBlock) cancelled;

+ (UIAlertView *) alertViewWithTitle:(NSString *)title
                             message:(NSString *)message
                   cancelButtonTitle:(NSString *)cancelButtonTitle
                   otherButtonTitles:(NSArray *)otherButtons
                      showsIndicator:(BOOL)showIndicator
                           onDismiss:(DismissBlock)dismissed
                            onCancel:(CancelBlock)cancelled;

+(UIAlertView*) alertViewWithTitle:(NSString *)title 
                           message:(NSString *)message
                 cancelButtonTitle:(NSString*) cancelButtonTitle
                    showsIndicator:(BOOL)showIndicator;

void LoadUIAlertViewNMBlock(void);



@end
