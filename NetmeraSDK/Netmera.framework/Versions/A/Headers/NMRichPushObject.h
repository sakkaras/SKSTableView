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

#import "Netmera.h"
#import "NMPushObject.h"

/**
 * NMRichPushObject class stores related data of a rich push message.
 */

@interface NMRichPushObject : NMPushObject

/**
 * HTML string that will be shown as rich push message content if any.
 */
@property (nonatomic, strong) NSString *htmlBody;

/**
 * Dictionary which contains custom parameters, which are sent with rich push message content.
 */
@property (nonatomic, strong) NSMutableDictionary *customParams;

/**
 * URL string that will bw shown as rich push content if any.
 */
@property (nonatomic, strong) NSString *urlString;

/**
 * Boolean value which indicates that the receiving rich push should be placed in Inbox
 */
@property (nonatomic, assign) BOOL shouldShownInInbox;

typedef enum
{
    PushInboxStatusNone,
    PushInboxStatusRead,
    PushInboxStatusUnread,
    PushInboxStatusDeleted
} PushInboxStatus;

/**
 * Status of the rich push according to functions to perform.
 *  @warning enum PushStatus options.
 *
 *      PushStatusRead, it shows that the rich push is read.
 *
 *      PushStatusUnread, it shows that the rich push is unread.
 *
 *      PushStatusDeleted, it shows that the rich push is deleted.
 */
@property (nonatomic,assign) PushInboxStatus pushInboxStatus;

/**
 * This method handles urls in the rich push content, and check whether related action contains a custom event. If yes, 
 *  it sends related event data to server.
 *
 *  @param url URL which is triggered in the rich push content.
 *
 *  @return BOOL returns YES if url contains a custom event. You should return NO to
 *      webView:shouldStartLoadWithRequest:navigationType: delegate method if this method returns YES.
 */
- (BOOL)handleEventURL:(NSURL*)url;


@end
