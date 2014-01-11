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

/**
 * version 2.0.1
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NMCore.h"
#import "NMGeolocation.h"
#import "NMDeviceDetail.h"
#import "NMUser.h"
#import "NMContent.h"
#import "NMService.h"
#import "NMPushManager.h"
#import "NMDeviceDetail.h"
#import "NMLocationManager.h"
#import "NMPushInboxCell.h"
#import "NMPushInboxList.h"
#import "NMRichPushObject.h"
#import "NMRichPushSenderObject.h"
#import "NMPushReport.h"
#import "NMEvent.h"
#import "NMExceptionReporter.h"
#import "NMReachability.h"
#import "NMNotificationController.h"
#import "NMProgressHUD.h"
#import "UIAlertView+NMBlockAdditions.h"
#import "NMPopupObject.h"
#import "NMPopupManager.h"
#import "NMJSONCategories.h"
#import "NMTwitterUtils.h"

#if defined(__has_include)
#if __has_include(<FacebookSDK/FacebookSDK.h>)
#import "NMFacebookUtils.h"
#else
#warning /Users/manuyavuz/Documents/FacebookSDK
#define NMFacebookUtils Add_FacebookSDK_To_Project_In_Order_To_Use_NMFacebookUtils
#endif
#endif

// SDKReleaseVersion
extern NSString * const kSDKReleaseVersion;

// Server Domain
extern NSString * const kServerDomain;

/**
 * Netmera class is the base class for Netmera SDK. You can configure how Netmera should behave using this class.
 *
 * Also, you can get InstallationId of your application using [Netmera getInstallationId] class method.
 */
@interface Netmera : NSObject

/**
 * Returns application-specific key received from Netmera and set in the application.
 *
 *  @return The string value which refers to api key.
 */
+ (NSString*)apiKey;

/**
 * Sets the application-specific key received from Netmera for the application requests.
 *
 * This value is unique for every application, therefore Netmera determines which app sends whichever requests. This 
 *  is the required value that must be set for every application before making any interaction with Netmera.
 *
 *  @param key The unique value received from "Overview" section of your application in Netmera website.
 *
 *  @discussion You can set the api key by either calling this method with the relevant parameter or adding manually
 *      it into NetmeraSettings.plist.
 */
+ (void)setApiKey:(NSString*)key;

/**
 * Returns a UUID string that could be used to uniquely identify the device for the application.
 *
 *  @return The string value generating exclusively for the application.
 */
+ (NSString*)getInstallationId;

/**
 * Sets a timeout value for all sending requests from Netmera SDK throughout the application. The default value is 60 
 *  seconds.
 *
 *  @param seconds Value used as the timeout interval for requests.
 *
 *  @discussion You should not set a short timeout interval, because this may prevents Netmera SDK to send requests in 
 *      weak internet connections.
 */
+ (void)setGlobalRequestTimeout:(NSTimeInterval)seconds;

/**
 * Returns the boolean value that shows whether the push inbox is enabled or not. The default value is YES.
 *
 *  @return The enabled or disabled boolean value.
 */
+ (BOOL)pushInboxEnabled;

/**
 * Sets the boolean value whether the push inbox controller is available for your application or not when a rich 
 *  push message is received. The default value is YES.
 *
 *  @param enabled The boolean value that enables push inbox or not.
 */
+ (void)setPushInboxEnabled:(BOOL)enabled;

/**
 * Returns the boolean value for receiving rich pushes to be displayed immediately or be asked whether rich pushes are
 *  displayed or not with an alert box. The default value is YES.
 *
 *  @return The boolean value that shows whether the rich push is shown immediately or not.
 */
+ (BOOL)richPushShouldBeShownImmediately;

/**
 * Sets the boolean value for receiving rich pushes to be displayed immediately or not. If shouldBeShown value is YES, 
 *  receiving rich push is displayed on the screen directly without any alert. If it is NO, then an alert box, which waits 
 *  a confirmation about if rich push should be shown or not from the user is shown on the screen. The default value is YES.
 *
 *  @param shouldBeShown The boolean value that controls the display of the rich pushes.
 */
+ (void)setRichPushShouldBeShownImmediately:(BOOL)shouldBeShown;

/**
 * Returns the boolean value which indicates whether a loading indicator is displayed or not when showing rich push 
 *  notifications. The default value is YES.
 *
 *  @return The boolean value showing that a progress HUD should be displayed or not.
 */
+ (BOOL)richPushShouldShowProgressHUD;

/**
 * Sets the boolean value whether a progress HUD should be displayed or not while setting up a receiving rich push 
 *  notification. The default value is YES.
 *
 *  @param shouldShow The boolean value that activates or deactivates a loading indicator.
 */
+ (void)setRichPushShouldShowProgressHUD:(BOOL)shouldShow;

/**
 * Returns the boolean value which indicates whether throwing exceptions should be reported or not. The default value is 
 *  YES.
 *
 *  @return The boolean value that enables or disables sending exception reports to Netmera throughout the application.
 */
+ (BOOL)exceptionReportingEnabled;

/**
 * Sets the boolean value that shows whether exceptionReporting should be enabled or disabled. Default value is YES.
 *
 *  If you enable exceptionReporting, the exceptions that are handled by you or crashes your application are catched by 
 *      Netmera SDK and send their reports to Netmera automatically. Then you can see your detailed reports in Netmera 
 *      website.
 *
 *  @param enabled The boolean value that enables exceptionReporting or not.
 *
 *  @discussion You can send your custom exception reports to Netmera, too. Just call sendExceptionReport: method of 
 *      NMExceptionReporter class. This method sends the report for the exception given as parameter independent from the 
 *      value of this flag.
 */
+ (void)setExceptionReportingEnabled:(BOOL)enabled;

/**
 * Returns the boolean value which indicates whether locationTracking is enabled or disabled. Default value is YES.
 *
 *  Users' locations are tracked by default (using startMonitoringSignificantLocationChanges method of CLLocationManager
 *    class). If you want to disable tracking user's location, you should call [NetmeraClient setLocationTrackingEnabled:NO]
 *    in application:didFinishLaunchingWithOptions: method in your app delegate.
 *
 *  @return The boolean value that enables or disables locationTracking.
 *
 *  @discussion This flag does NOT affect operation of Geofence Service. You can start or stop a geofence service 
 *      regardless of this flag.
 */
+ (BOOL)significantLocationChangeTrackingEnabled;

/**
 * Sets the boolean value that shows whether locationTracking should be enabled or disabled. Default value is YES.
 *
 * Users' locations are tracked by default (using startMonitoringSignificantLocationChanges method of CLLocationManager
 *  class). If you want to disable tracking user's location, you should call [NetmeraClient setLocationTrackingEnabled:NO] 
 *  in application:didFinishLaunchingWithOptions: method in your app delegate.
 *
 *  @param enable The boolean value that enables locationTracking or not.
 *
 *  @discussion This flag does NOT affect operation of Geofence Service. You can start or stop a geofence service 
 *  regardless of this flag.
 */
+ (void)setSignificantLocationChangeTrackingEnabled:(BOOL)enabled;

@end


