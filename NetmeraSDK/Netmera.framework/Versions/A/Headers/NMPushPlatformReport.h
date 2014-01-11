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

/**
 * NMPushPlatfromReport class is used to present the information about a push notification sent to a certain platform.
 *  These platfroms can be iOS, Android or Windows Phone.
 */

typedef enum {
    NotificationDrafted,
    NotificationSending,
    NotificationFinished,
    NotificationFailed
} NotificationStatus;

typedef enum {
    NotificationPushPlatformIOS,
    NotificationPushPlatformAndroid,
    NotificationPushPlatformWP
} NotificationPushPlatform;

@interface NMPushPlatformReport : NSObject

/**
 * Name of the platform-specific information of the push notification.
 *
 *  @warning enum NotificationPushPlatform options.
 *
 *      NotificationPushPlatformIOS, 'IOS' Platform.
 *
 *      NotificationPushPlatformAndroid, 'Android' Platform.
 *
 *      NotificationPushPlatformWP, 'WP' Platform.
 */
@property (nonatomic, readonly, assign) NotificationPushPlatform platform;

/**
 * Date of the push notification, which is started to send to the devices that are registrated to the relevant platform .
 */
@property (nonatomic, readonly, strong) NSDate *sendDate;

/**
 * Date of the push notification, which is finished to send to the devices that are registered to the relevant platform.
 */
@property (nonatomic, readonly, strong) NSDate *finishedDate;

/**
 * Status of the created push notification object of the relevant platform.
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
 * Number of the devices that received the platform-based push notification successfully.
 */
@property (nonatomic, readonly, assign) NSUInteger successCount;

/**
 * Number of the devices that could not receive the platform-based push notification.
 */
@property (nonatomic, readonly, assign) NSUInteger failedCount;

/**
 * Cause of the error if it occured while sending the platform-based push notification.
 */
@property (nonatomic, readonly, strong) NSString *platformErrorDescription;

/**
 * Converts NotificationStatus enum type into string format that refers to notification status.
 *
 *  @param status Enum type of the push notification status.
 *
 *  @return Corresponding string of the push notification status.
 */
+ (NSString *)stringFromNotificationStatus:(NotificationStatus)status;


@end
