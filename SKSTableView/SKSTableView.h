//
//  SKSTableView.h
//  SKSTableView
//
//  Created by Sakkaras on 26/12/13.
//  Copyright (c) 2013 Sakkaras. All rights reserved.
//

#import <UIKit/UIKit.h>

/** 
 *  SKSTableView is a custom table view class extended from UITableView class. This class provides a single-level hierarchical
 *  structure for your contents. In order to minimalize the effectiveness of the table view, the default insertion and remove 
 *  mechanism of UITableView (insertRowsAtIndexPaths:withRowAnimation: and deleteRowsAtIndexPaths:withRowAnimation:) is used.
 *  Main rows of your table view, which can be expandable or not must be instances of SKSTableViewCell class. Subrows can be
 *  instances of any class that is extended from UITableViewCell.
 */

@class SKSTableView;

#pragma mark - SKSTableViewDelegate

@protocol SKSTableViewDelegate <UITableViewDataSource, UITableViewDelegate>

@required

/**
 * Returns the number of the subrows for the expandable row at the given index path.
 *
 *  @param tableView The instance of SKSTableView class which delegate is set.
 *
 *  @param indexPath The index path of the expandable row. It is the value for the expandable row before expanding.
 *
 *  @return The number of the subrows.
 */
- (NSInteger)tableView:(SKSTableView *)tableView numberOfSubRowsAtIndexPath:(NSIndexPath *)indexPath;

/**
 * Returns the instance of UITableViewCell object for the cell at the given indexPath.
 *
 *  @param tableView The instance of SKSTableView class which delegate it set.
 *
 *  @param indexPath The index path for the subrow. It has three properties that shows the exact position of the subrow cell.
 *                      These properties are named as section, row and subrow, all of which refers to the index of the object 
 *                      at the content array defined as data source of the table view.
 *
 *  @return The instance for the cell of subrow at the given indexPath.
 *
 *  @discussion In order to implement SKSTableView class efficiently, your content for the data source of the table view should
 *                  be designed as:
 *                      
 *                                  contentArray[[(Section0)[row0,subrow1,subrow2,...],[row1,subrow1,subrow2,...],
 *                                  [row2, subrow1,subrow2,...],...],[(Section1)[...],[...],[...], ...],...]
 *
 *                  and indexPath for any subrow is formatted as below:
 *
 *                                  Section0-row1-subrow2 => NSIndexPath section = 0 / row = 1 / subrow = 2 (Third element of
 *                                                                                     the first element of the content array.)
 *
 *                 For further information, please check the sample table view[@ViewController] in the project.
 */
- (UITableViewCell *)tableView:(SKSTableView *)tableView cellForSubRowAtIndexPath:(NSIndexPath *)indexPath;

@end


@interface SKSTableView : UITableView

/**
 * The delegate for the SKSTableViewDelegate protocol.
 *
 *  @discussion You must set only this protocol for the delegation and the datasource of SKSTableView instance.
 */
@property (nonatomic, weak) id <SKSTableViewDelegate> SKSTableViewDelegate;

@end


#pragma mark - NSIndexPath (SKSTableView)

@interface NSIndexPath (SKSTableView)

/**
 * Subrow number of the indexPath for any cell object.
 */
@property (nonatomic, assign) NSInteger subRow;

/**
 * Initializes the newly-allocated NSIndexPath object with the given parameters.
 *
 *  @param subrow Subrow of the NSIndexPath object.
 *
 *  @param row Row of the NSIndexPath object.
 *
 *  @param section Section of the NSIndexPath object.
 *
 *  @return An initialized NSIndexPath object.
 */
+ (NSIndexPath *)indexPathForSubRow:(NSInteger)subrow inRow:(NSInteger)row inSection:(NSInteger)section;

@end
