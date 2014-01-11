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

typedef enum {
    NotificationTypeStandard,
    NotificationTypeRich,
    NotificationTypeURLPush,
    NotificationTypePopup
} NotificationType;

/**
 * NMRichPushObject class is used to store related data of a plain push message.
 */

@interface NMPushObject : NSObject

/** 
 * Plain message of the push notification.
 */
@property (nonatomic, strong) NSString *alertText;

/** 
 * Custom payload information that sent with push notification.
 */
@property (nonatomic, strong) NSMutableDictionary *customPayload;

/**
 * Id of the push notification that is sent to the devices.
 */
@property (nonatomic, strong) NSString *notificationId;

/** 
 * Creation Date of the push notification.
 */
@property (nonatomic, strong) NSDate *createDate;

/**
 * Type of the created push notification object.
 *
 *  @warning enum NotificationType options.
 *
 *      NotificationTypeStandard, plain-text push notification is sent to the relevant devices.
 *
 *      NotificationTypeRich, push notification that contains HTML-formatted rich content is sent to the relevant devices.
 *
 *      NotificationTypePopup, pop-up object that contains HTML-formatted content.
 *
 *      NotificationTypeURLPush, push notification that contains an URL for the rich content is sent to the relevant devices.
 */
@property (nonatomic, assign) NotificationType type;

/**
 * Converts a relevant string format into NotificationType enum type.
 *
 *  @param typeString String representation of the push notification type.
 *
 *  @return Corresponding enum type of the push notification type.
 */
+ (NotificationType)notificationTypeFromString:(NSString *)typeString;

/**
 * Converts NotificationType enum type into string format that refers to notification type.
 *
 *  @param type Enum type of the push notification type.
 *
 *  @return Corresponding string of the push notification type.
 */
+ (NSString *)stringFromNotificationType:(NotificationType)type;

@end
