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

#import "NMRichPushSenderObject.h"
#import "NMPushPlatformReport.h"

/**
 * NMPushReport class is used to present the relevant information about a push notification specified by notification id.
 */

@interface NMPushReport : NMRichPushSenderObject

/**
 * Status of the created push notification object.
 *
 *  @warning enum NotificationStatus options.
 *
 *      NotificationDrafted, means the push notification is saved as draft.
 *
 *      NotificationSending, means the push notification is still sending to the devices.
 *
 *      NotificationFinished, means the push notification was sent to relevant devices.
 *
 *      NotificationFailed, means the sending the push notification to relevant devices is failed.
 */
@property (nonatomic, readonly, assign) NotificationStatus status;

/**
 * Platform-specific information of the push notification if it is sent to IOS devices.
 */
@property (nonatomic, readonly, strong) NMPushPlatformReport *iOSPlatform;

/**
 * Platform-specific information of the push notification if it is sent to Android devices.
 */
@property (nonatomic, readonly, strong) NMPushPlatformReport *androidPlatform;

/**
 * Platform-specific information of the push notification if it is sent to Windows Phone devices.
 */
@property (nonatomic, readonly, strong) NMPushPlatformReport *WPPlatform;

/**
 * Fetches the report information of the sending push notification which is is known on the background thread.
 *
 *  @param notificationId NotificationID of the push notification of which report is requested to get.
 *
 *  @param handler The block to execute when the receiving the report of the push notification is completed.
 */
+ (void)getNotificationReportWithId:(NSString *)notificationId completionHandler:(void(^)(NMPushReport *notificationReport, NSError *error))handler;

@end
