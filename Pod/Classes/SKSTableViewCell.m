//
//  SKSTableViewCell.m
//  SKSTableView
//
//  Created by Sakkaras on 26/12/13.
//  Copyright (c) 2013 Sakkaras. All rights reserved.
//

#import "SKSTableViewCell.h"
#import "SKSTableViewCellIndicator.h"

#define kIndicatorViewTag -1

@interface SKSTableViewCell ()

@end

@implementation SKSTableViewCell

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        self.expandable = YES;
        self.expanded = NO;
    }
    return self;
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    
    if (self.isExpanded) {
        
        if (![self containsIndicatorView])
            [self addIndicatorView];
        else {
            [self removeIndicatorView];
            [self addIndicatorView];
        }
    }
}

static UIImage *_image = nil;
- (UIView *)expandableView
{
    if (!_image) {
        _image = [UIImage imageNamed:@"expandableImage.png"];
    }
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    CGRect frame = CGRectMake(0.0, 0.0, _image.size.width, _image.size.height);
    button.frame = frame;
    
    [button setBackgroundImage:_image forState:UIControlStateNormal];
    
    return button;
}

- (void)setExpandable:(BOOL)isExpandable
{
    if (isExpandable)
        [self setAccessoryView:[self expandableView]];
    
    _expandable = isExpandable;
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated
{
    [super setSelected:selected animated:animated];
}

- (void)addIndicatorView
{
    CGPoint point = self.accessoryView.center;
    CGRect bounds = self.accessoryView.bounds;
    
    CGRect frame = CGRectMake((point.x - CGRectGetWidth(bounds) * 1.5), point.y * 1.4, CGRectGetWidth(bounds) * 3.0, CGRectGetHeight(self.bounds) - point.y * 1.4);
    SKSTableViewCellIndicator *indicatorView = [[SKSTableViewCellIndicator alloc] initWithFrame:frame];
    indicatorView.tag = kIndicatorViewTag;
    [self.contentView addSubview:indicatorView];
}

- (void)removeIndicatorView
{
    id indicatorView = [self.contentView viewWithTag:kIndicatorViewTag];
    if (indicatorView)
    {
        [indicatorView removeFromSuperview];
        indicatorView = nil;
    }
}

- (BOOL)containsIndicatorView
{
    return [self.contentView viewWithTag:kIndicatorViewTag] ? YES : NO;
}

- (void)accessoryViewAnimation
{
    [UIView animateWithDuration:0.2 animations:^{
        if (self.isExpanded) {
            
            self.accessoryView.transform = CGAffineTransformMakeRotation(M_PI);
            
        } else {
            self.accessoryView.transform = CGAffineTransformMakeRotation(0);
        }
    } completion:^(BOOL finished) {
        
        if (!self.isExpanded)
            [self removeIndicatorView];
        
    }];
}

@end
