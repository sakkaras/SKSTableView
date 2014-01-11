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

#import "NMPushSenderObject.h"

/**
 * NMRichPushSenderObject class is used to send html-formatted content. By using this class, push notifications that
 *  contains well-designed html pages can be sent instead of plain text notifications.
 */

@interface NMRichPushSenderObject : NMPushSenderObject

/**
 * String representation of rich push notification HTML. This property is required.
 */
@property (nonatomic, strong) NSString *htmlString;

 /**
 * Initializes the newly allocated NMRichPushSenderObject with the specified title, alert text and rich push HTML values
 *  of push notification.
 *
 *  @param title Title of the push notification.
 *
 *  @param text Message of the push notification.
 *
 *  @param htmlText String representation of rich push HTML content of the push notification.
 *
 *  @return An initialized NMRichPushSenderObject object with given parameters.
 */
- (id)initWithTitle:(NSString *)title alertText:(NSString *)text richPushHTML:(NSString *)htmlText;

@end
