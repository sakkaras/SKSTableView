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

#import "NMPushObject.h"

/**
 * NMPushSenderObject class is used to send plain-text push notification to the devices with certain properties. 
 *  By using this class, different properties that serve your needs of the push notification can be set. By default, 
 *  you have to set 'Title' and 'Alert Text' properties. Other properties are optional. Just if 'Token' property is set,
 *  'Tags' and 'Platforms' properties will be ignored. In Netmera Push Backend Service, token has higher priority.
 *  'Location Info' and 'Platform' properties are readonly, however, these properties can be set via 
 *  setPushCircleLocationInfoWithCenterLocation:distance:, setPushBoxLocationInfoWithFirstLocation:secondLocation:
 *  and setTargetPushPlatform: methods in order to prevent to send invalid values.
 */

typedef enum {
    PushPlatformIOS = 1 << 0,
    PushPlatformAndroid = 1 << 1,
    PushPlatformWp = 1 << 2
} PushPlatform;

@interface NMPushSenderObject : NMPushObject

/**
 * Title of the push notification object. This property is required.
 */
@property (nonatomic, strong) NSString *title;

/**
 * Location information, of which the area where the push notification is sent. It contains push type and relevant
 *  geo-locations. This property is optional.
 */
@property (nonatomic, readonly, strong) NSDictionary *locationInfo;

/**
 * Token of the device, which will be requested to send the push notification. This property is optional.
 */
@property (nonatomic, strong) NSString *token;

/**
 * Tags of the devices, which will receive the sending the push notification. If not set, then the push notification
 *  is sent to all devices(Default Tag: BROADCAST). This property is optional.
 */
@property (nonatomic, strong) NSMutableArray *tags;

/**
 * Platforms of the devices, which will be receive the sending push notification. By default, the push notification is
 *  sent to device of all platforms. This property is read-only.
 */
@property (nonatomic, readonly, strong) NSArray *platforms;

/**
 * Sets location info with 'Circle' type. This set-up enables the devices only-located inside the given area to receive 
 *  sending push notification.
 *
 *  @param location Center location of the circle area.
 *
 *  @param distance Radius of the circle area.
 */
- (void)setPushCircleLocationInfoWithCenterLocation:(NMGeolocation *)location
                                           distance:(double)distance;

/**
 * Sets location info with 'Box' type. This set-up enables the devices only-located inside the given area to receive
 *  sending push notification.
 *
 *  @param firstLocation One of the corners of the box area.
 *
 *  @param secondLocation Diagonal corner of the first location of the box area.
 */
- (void)setPushBoxLocationInfoWithFirstLocation:(NMGeolocation *)firstLocation
                                 secondLocation:(NMGeolocation *)secondLocation;

/**
 * Sets the platforms of the devices, which will be intended to send the push notification.
 *
 *  @param platforms Corresponding enum values of the platforms. You can set multiple platforms by put OR(|) operator
 *      between enum values.
 *
 *  @warning Available enum PushPlatform options.
 *
 *      PushPlatformIOS, 'IOS' platform.
 *
 *      PushPlatformAndroid, 'Android' platform.
 *
 *      PushPlatformWp, 'Windows Phone' platform.
 */
- (void)setPushPlatform:(PushPlatform)platforms;

/**
 * Initializes the newly allocated NMPushSenderObject with the specified title and alert text values of push notification.
 *
 *  @param title Title of the push notification.
 *
 *  @param text Message of the push notification.
 *
 *  @return An initialized NMPushSenderObject object with given parameters.
 */
- (id)initWithTitle:(NSString *)title alertText:(NSString *)text;

/** 
 * Key-value pair as given parameter is used to filter the device(s) that will receive push notifications over the value
 *  of customDictionary of NMDeviceDetail object while registering to NMPushManager.
 *
 *  @param key Key value for filtering the registered pairs.
 *
 *  @param value Object value for filtering the registered pairs.
 *
 *  @return Receiver NMPushSenderObject object.
 *
 *  @discussion Multiple key-value pairs can be set while sending push notifications using this method. Therefore, push
 *      notification will be sent to the device(s) that contain all key-value pairs.
 */
- (NMPushSenderObject *)whereEqualWithCustomField:(NSString *)key value:(id)value;

/**
 * Sends the push notification on the background thread.
 *
 *  @param handler The block to execute when the sending push notification is completed.
 */
- (void)sendPushNotificationWithCompletionHandler:(void(^)(NSString *notificationId, NSError *error))handler;

@end
