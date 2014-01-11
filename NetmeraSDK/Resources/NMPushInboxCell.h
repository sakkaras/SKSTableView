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

#import <UIKit/UIKit.h>

/** 
 * NMPushInboxCell is the class, which customizes the cells of the table that is used to display the rich push notifications. 
 *  It basicly shows the message and date of the rich push notification.
 * You can fully customize this class because it's included in the SDK as open source.
 */

@interface NMPushInboxCell : UITableViewCell

/** 
 * Returns the row height of the table cell.
 *
 *  @return the value of the cell height.
 */
+ (CGFloat)rowHeight;

/** 
 * Message of the rich push notification.
 */
@property (assign, nonatomic) IBOutlet UILabel *pushMessageLabel;

/**
 * Date of the rich push notification.
 */
@property (assign, nonatomic) IBOutlet UILabel *dateLabel;

@end
