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
#import "NMGeolocation.h"

/**
 * NMDeviceDetail class is used to get the information of the device registered to push notification service of Netmera. 
 *  Therefore, tags, location or custom key-value pairs of the registered device can be accessed easily. Moreover, these fields 
 *  must be first set on the NMDeviceDetail object and then the device can be registered to 'Netmera Push Service' with these 
 *  properties
 */

@interface NMDeviceDetail : NSObject

/** 
 * Location of the registered device.
 *
 *  @discussion This value refers to the last location of the device that can be stored in Netmera.
 */
@property (nonatomic, strong) NMGeolocation *location;

/**
 * Custom key-value pairs that can be used to specify the device.
 */
@property (nonatomic, strong) NSMutableDictionary *customDictionary;

/**
 * Returns the deviceToken received from APNS (Apple Push Notification Service) while registering the device. This value is
 *  hold automatically by Netmera SDK and provide the uniqueness of the device for push notifications.
 *
 *  @return Token of the device retrieved from application:didRegisterForRemoteNotificationsWithDeviceToken: delegate method.
 */
- (NSString *)deviceToken;

#pragma mark - tag handling

/**
 * Returns the current tags of the device registered to 'Netmera Push Service'. The device should receive a push notification
 *  if it is sent to the devices with one of the registered tags.
 */
- (NSArray *)getTags;

/**
 * Overrides the current tags of the device registered to 'Netmera Push Service' with the given tag collection.
 *
 *  @param tags Array of the tags which overrides the current ones of the device.
 *
 *  @discussion This method should be called carefully, because once the current tags of the device is overridden, there is
 *      no turning back to old tags.
 *   This method does not register the given tags to 'Netmera Push Service' automatically. You should call
 *      registerWithDeviceDetail:completionHandler: method of NMPushManager with the receiver NMDeviceDetail object.
 */
- (void)overrideTagsWithNewTags:(NSArray *)tags;

/**
 * Adds a tag into the receiver NMDeviceDetail object. Using the receiver object, the device can be registered to or unregistered
 * from 'Netmera Push Service' for the given tag.
 *
 *  @param tag Tag which is used to register/unregister the device to/from 'Netmera Push Service'.
 *
 *  @discussion This method does not register to or unregister from 'Netmera Push Service' for the given tag automatically. You 
 *      should call registerWithDeviceDetail:completionHandler: or unregisterWithDeviceDetail:completionHandler: method of 
 *      NMPushManager with the receiver NMDeviceDetail object.
 */
- (void)addTag:(NSString *)tag;

/**
 * Adds multiple tags into the receiver NMDeviceDetail object. Using the receiver object, the device can be registered to or 
 *  unregistered from 'Netmera Push Service' for the given tag array.
 *
 *  @param tags Array of the tags which are used to register/unregister the device to/from 'Netmera Push Service'.
 *
 *  @discussion This method does not register to or unregister from 'Netmera Push Service' for the given tags automatically. You
 *      should call registerWithDeviceDetail:completionHandler: or unregisterWithDeviceDetail:completionHandler: method of
 *      NMPushManager with the receiver NMDeviceDetail object.
 */
- (void)addTags:(NSArray*)tags;

/**
 * Fetches the detail of the device registered to 'Netmera Push Service' on the background thread.
 *
 *  @param handler The block to execute when the fetch of the device detail is completed.
 */
+ (void)getDeviceDetailWithCompletionHandler:(void(^)(NMDeviceDetail *deviceDetail, NSError *error))handler;

@end
