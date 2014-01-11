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
#import "NMProgressHUD.h"

typedef void(^RichPushCompletionHandler)(NSError *error);

/**
 * NMPushManager class is used to manage all issues about push notifications. All issues mean registering to and 
 *  unregistering from 'Push Notification's, getting the registered device tags and also rich push handling mechanism. 
 *  Even if you are able to use these methods whenever you want, you should be aware of the fact that Netmera iOS 
 *  SDK v2.0 and after versions already will handle all these issues automatically while there is no need to write any code except the extreme
 *  scenarios after adding the SDK to your application.
 */

@interface NMPushManager : NSObject

/**
 * Returns the NSString representation of the 'deviceToken', is given by APNS in the delegate method 
 *  application:didRegisterForRemoteNotificationsWithDeviceToken:.
 *
 *  @discussion If the device is requested to be registered in the application code, i.e. the situation that requires tag 
 *      registration, besides application:didRegisterForRemoteNotificationsWithDeviceToken: method, this value is used 
 *      automatically.
 */
+ (NSString *)deviceToken;

/**
 * Registers the device to Netmera for push notifications on the background thread.
 *
 *  @param handler The block to execute when the registration of the device is completed.
 */
+ (void)registerWithCompletionHandler:(void(^)(BOOL deviceDidRegister, NSError *error))handler;

/**
 * Registers the device with the related attributes, namely tag, customDictionary and location, on the background thread.
 *
 *  @param deviceDetail The NMDeviceDetail object which contains the relevant attributes.
 *
 *  @param handler The block to execute when the registration of the device with the given attributes is completed.
 */

+ (void)registerWithDeviceDetail:(NMDeviceDetail *)deviceDetail completionHandler:(void(^)(BOOL deviceDidRegister, NSError *error))handler;

/**
 * Unregisters the device completely from Netmera for push notifications on the background thread.
 *
 *  @param handler The block to execute when the unregistration of the device is completed.
 */
+ (void)unregisterWithCompletionHandler:(void(^)(BOOL deviceDidUnregister, NSError *error))handler;

/**
 * Unregisters the device from the tags that just set on the given NMDeviceDetail object on the background thread.
 *
 *  @param deviceDetail The NMDeviceDetail object which contains the tags that are unregistered from.
 *
 *  @param handler The block to execute when the unregistration of the device from the given tags is completed.
 */
+ (void)unregisterWithDeviceDetail:(NMDeviceDetail *)deviceDetail completionHandler:(void(^)(BOOL deviceDidUnregister, NSError *error))handler;

/**
 * Returns all tags registered to your application on the background thread.
 *
 *  @param handler The block to execute when the fetch of the tags is completed.
 *
 *  @discussion You should beware that tag list returned from this method contains the tags other devices registered to, 
 *      not just the regarding device.
 */
+ (void)getDeviceTagsWithCompletionHandler:(void(^)(NSArray *tags, NSError *error))handler;

#pragma mark - Rich Push Handling

/**
 * Shows that the receiving push notification is rich or standard.
 *
 *  @return The boolean value which represents type of the coming push notification handled by SDK automatically.
 *
 *  @discussion Netmera iOS SDK v2.0 and after versions will handle the receiving rich push notifications automatically. There is no need to write a 
 *      single line code for present rich push notification. However, you want to make some changes in your application 
 *      independent from the SDK or showing standard push notifications within your app style; therefore, you can be aware of 
 *      the type of the coming rich push notification calling this method.
 */
+ (BOOL)isRichPushReceived;

/**
 * Returns the block which is executed after a rich push notification is displayed on the device.
 *
 *  @return The block to be executed when showing the rich push notification is completed.
 */
+ (RichPushCompletionHandler)richPushCompletionHandler;

/**
 * Sets the block which is executed on completion of display of a rich push notification.
 *
 *  @param handler The block to be executed when showing the rich push notification is completed.
 */
+ (void)setRichPushCompletionHandler:(RichPushCompletionHandler)handler;

/**
 * Use this method to manually present push inbox on your view controller hierarchy. Push Inbox controller will be 
 *  presented on given controller as a modalviewcontroller.
 *
 *  @param parentController The controller object which will present push inbox modally.
 */
+ (void)presentPushInboxFromController:(UIViewController*)parentController;

/*
 * Following two methods determines the time intervals at which rich push notifications that comes during app is runnning
 *  should be shown to user or not.
 * By default, coming rich pushes are shown to users according to specified presentation procedure (which is determined by
 *  RichPushShouldBeShownImmediately key in NetmeraSettings.plist file).
 * If you call [NMPushManager beginIgnoringRichPushes] method in your code, received rich pushes during foreground state 
 *  will be ignored by Netmera, and won't be shown to user, until
 *
 *      [NMPushManager endIgnoringRichPushes] method is called.
 */
/**
 * Method which makes Netmera to ignore received rich pushes when application is on the foreground so that rich pushes does 
 *  NOT interrupt users' actions.
 *
 *  @discussion If you call [NMPushManager beginIgnoringRichPushes] method in your code, received rich pushes during 
 *      foreground state will be ignored by Netmera, and won't be shown to user, until [NMPushManager endIgnoringRichPushes]
 *      method is called.
 */
+ (void)beginIgnoringRichPushes;

/**
 * Method which makes Netmera to stop ignoring received rich pushes when application is on the foreground so that rich 
 *  pushes will be shown to user after this call.
 */
+ (void)endIgnoringRichPushes;

/**
 * Method that removes push inbox controller from memory.
 */
+ (void)clearPushInbox;

/**
 * Method that removes rich push controller from memory. It's called when push inbox is disabled.
 */
+ (void)clearRichPush;

/**
 * Returns the indicator object used for the process of the loading of a rich push notification and push inbox.
 *
 *  @return NMProgressHUD object that is set for the loading indicator.
 */
+ (NMProgressHUD *)loadingHUD;

/**
 * Sets the indicator object used for the process of the loading of a rich push notification and push inbox.
 *
 *  @param progressHUD Configured loading indicator.
 *
 *  @discussion For a custom loading indicator, you should configure NMProgressHUD object. It offers a rich interface. 
 *      By default, a basic design of NMProgressHUD is used.
 */
+ (void)setLoadingHUD:(NMProgressHUD *)progressHUD;

/**
 * Controls the availability of a rich push notification to show. Existance of internet connection is considered in the 
 *  scope of availability.
 *
 *  @return availability of rich push notification.
 */
+ (BOOL)checkAvailability;

@end
