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
#import <Netmera/Netmera.h>
@class NMPushObject;

/**
 * NMPushInboxViewController is the controller  basic yet visually beautiful implementation of the PushInbox. It basicly 
 *  provides a tableView based interface to users in which they can access, read and delete rich push notifications that 
 *  they received.
 * You can fully customize this class because it's included in the SDK as open source.
 */

@interface NMPushInboxViewController : UIViewController<UINavigationControllerDelegate,UITableViewDataSource,UITableViewDelegate, UIActionSheetDelegate, UIAlertViewDelegate, NMPushInboxListDelegate>

/**
 * Returns the current logged user. Returns nil if there is no login user.
 *
 *  @param rich push object that is recently received.
 */
- (void)notificationFetchedWithPushObject:(NMPushObject *)object;

/** 
 * Table of the rich push notifications that have been sent.
 */
@property (nonatomic,unsafe_unretained) IBOutlet UITableView *tableView;

/**
 * Image view when no rich push notification exists.
 */
@property (nonatomic,unsafe_unretained) IBOutlet UIImageView *emptyImageView;

/**
 * Boolean value which indicates whether richPush show process continues
 */
@property (nonatomic,assign) BOOL richPushIsAnimating;

/**
 * Rich push object of receiving a notification which push inbox controller presents.
 */
@property (nonatomic, strong) NMRichPushObject *richPush;

@end
