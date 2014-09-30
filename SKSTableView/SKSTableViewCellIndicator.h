//
//  SKSTableViewCellExpandedIndicatorView.h
//  SKSTableView
//
//  Created by Sakkaras on 04/01/14.
//  Copyright (c) 2014 Sakkaras. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  SKSTableViewCellIndicator is a custom class extended from UIView class. It is used to add a indicator view as subview for 
 *  the SKSTableViewCell object when it is expanded.
 */

@interface SKSTableViewCellIndicator : UIView

/**
 * Returns the color of the indicator view.
 *
 *  @discussion By default, this value equals to the seperator color of the table view, and if the seperator color is changed,
 *               the color of the indicator value is set automatically, too.
 */
+ (UIColor *)indicatorColor;

/**
 * Sets the color of the indicator view.
 *
 *  @param indicatorColor The color of the indicator view.
 */
+ (void)setIndicatorColor:(UIColor *)indicatorColor;

@end
