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

@class NMUser;

/**
 * NMFacebookUtils class is used to perform user operations with a Facebook account. In order to benefit from this class 
 *  properly, you should add Facebook SDK into your project and make necessary configurations to be able to access 
 *  to a Facebook account.
 */

@interface NMFacebookUtils : NSObject

/**
 * Returns the FacebookAppID, which is set for the application in order to perform login operations with a Facebook account. 
 *  If this id is not set, then any login operation regarding Facebook can not be done.
 *
 *  @return The FacebookAppID that is set for the application. Returns nil if there is no FacebookAppID.
 */
+ (NSString *)facebookAppId;

/**
 * Sets the FacebookAppID for the application in order to perform login operations with a Facebook account. If this id 
 *  is not set, then any login operation regarding Facebook can not be done.
 *
 *  @param The NSString representation of the appID obtained from Facebook developer website.
 *
 *  @discussion It is recommended to set FacebookAppID with the relevant key-value pair in Info.plist
 */
+ (void)setFacebookAppId:(NSString *)appId __deprecated;

/**
 * Logs on a user with a Facebook account for the registered application without any read permissions. It is not allowed 
 *  to pass publish permissions to this method.
 *
 *  @param handler The block to execute when login with a Facebook account is completed.
 *
 *  @discussion After you login on the application with a Facebook, a NMUser object associated with the Facebook account is 
 *      created over cloud automatically. You can access this newly-created user in completion handler. The default login 
 *      flow sequence that the Facebook SDK implements:
 *          1. iOS Login Dialog (The account credentials in Facebook section in Settings application.)
 *          2. Facebook App Native Login Dialog
 *          3. Facebook App Web Login Dialog
 *          4. Mobile Safari Login Dialog
 */
+ (void)loginWithCompletionHandler:(NMUserResponseHandler)handler;

/**
 * Logs on a user with a Facebook account for the registered application without any read permissions. It is not allowed 
 *  to pass publish permissions to this method.
 *
 *  @param appId The FacebookAppID that is set for the application.
 *
 *  @param handler The block to execute when login with a Facebook account is completed.
 *
 *  @discussion After you login on the application with a Facebook, a NMUser object associated with the Facebook account is 
 *      created over cloud automatically. You can access this newly-created user in completion handler. The default login 
 *      flow sequence that the Facebook SDK implements:
 *          1. iOS Login Dialog (The account credentials in Facebook section in Settings application.)
 *          2. Facebook App Native Login Dialog
 *          3. Facebook App Web Login Dialog
 *          4. Mobile Safari Login Dialog
 */
+ (void)loginWithFacebookAppId:(NSString *)appId completionHandler:(NMUserResponseHandler)handler __deprecated;

/**
 * Logs on a user with a Facebook account for the registered application with the given read permissions. It is not allowed 
 *  to pass publish permissions to this method. However, if publish permissions are needed, you may use 
 *  requestNewPublishPermissions:defaultAudience:completionHandler: to specify additional permissions as well as an audience.
 *
 *  @param permissions An array of strings representing the read permissions to request during the authentication flow.
 *
 *  @param handlerThe block to execute when login with a Facebook account is completed.
 *
 *  @discussion After you login on the application with a Facebook, a NMUser object associated with the Facebook account is 
 *      created over cloud automatically. You can access this newly-created user in completion handler. The default login 
 *      flow sequence that the Facebook SDK implements:
 *          1. iOS Login Dialog (The account credentials in Facebook section in Settings application.)
 *          2. Facebook App Native Login Dialog
 *          3. Facebook App Web Login Dialog
 *          4. Mobile Safari Login Dialog
 */
+ (void)loginWithPermissions:(NSArray *)permissions completionHandler:(NMUserResponseHandler)handler;

/**
 * Logs on a user with a Facebook account for the registered application with the given read permissions. It is not allowed 
 *  to pass publish permissions to this method. However, if publish permissions are needed, you may use 
 *  requestNewPublishPermissions:defaultAudience:completionHandler: to specify additional permissions as well as an audience.
 *
 *  @param permissions An array of strings representing the read permissions to request during the authentication flow.
 *
 *  @param appId The FacebookAppID that is set for the application.
 *
 *  @param handler The block to execute when login with a Facebook account is completed.
 *
 *  @discussion After you login on the application with a Facebook, a NMUser object associated with the Facebook account is 
 *      created over cloud automatically. You can access this newly-created user in completion handler. The default login 
 *      flow sequence that the Facebook SDK implements:
 *          1. iOS Login Dialog (The account credentials in Facebook section in Settings application.)
 *          2. Facebook App Native Login Dialog
 *          3. Facebook App Web Login Dialog
 *          4. Mobile Safari Login Dialog
 */
+ (void)loginWithPermissions:(NSArray *)permissions facebookAppId:(NSString *)appId completionHandler:(NMUserResponseHandler)block __deprecated;

/**
 * Logs the user out of the application. This method also closes out the Facebook session in memory and clears out 
 *  an persisted cache of token data.
 */
+ (void)logout;

// The constants for permissions for Facebook login.

/**
 * Facebook permission key constant for "user_about_me"
 */
extern NSString * const facebook_permission_user_about_me;

/** 
 * Facebook permission key constant for "friends_about_me"
 */
extern NSString * const facebook_permission_friends_about_me;

/** 
 * Facebook permission key constant for "user_activities"
 */
extern NSString * const facebook_permission_user_activities;

/** 
 * Facebook permission key constant for "friends_activities"
 */
extern NSString * const facebook_permission_friends_activities;

/** 
 * Facebook permission key constant for "user_birthday"
 */
extern NSString * const facebook_permission_user_birthday;

/** 
 * Facebook permission key constant for "friends_birthday"
 */
extern NSString * const facebook_permission_friends_birthday;

/** 
 * Facebook permission key constant for "user_checkins"
 */
extern NSString * const facebook_permission_user_checkins;

/**
 * Facebook permission key constant for "friends_checkins"
 */
extern NSString * const facebook_permission_friends_checkins;

/**
 * Facebook permission key constant for "user_education_history"
 */
extern NSString * const facebook_permission_user_education_history;

/** 
 * Facebook permission key constant for "friends_education_history"
 */
extern NSString * const facebook_permission_friends_education_history;

/**
 * Facebook permission key constant for "user_events"
 */

extern NSString * const facebook_permission_user_events;
/** 
 * Facebook permission key constant for "friends_events"
 */
extern NSString * const facebook_permission_friends_events;

/**
 * Facebook permission key constant for "user_groups"
 */
extern NSString * const facebook_permission_user_groups;

/** 
 * Facebook permission key constant for "friends_groups"
 */
extern NSString * const facebook_permission_friends_groups;

/** 
 * Facebook permission key constant for "user_hometown"
 */
extern NSString * const facebook_permission_user_hometown;

/** 
 * Facebook permission key constant for "friends_hometown"
 */
extern NSString * const facebook_permission_friends_hometown;

/**
 * Facebook permission key constant for "user_interests"
 */
extern NSString * const facebook_permission_user_interests;

/** 
 * Facebook permission key constant for "friends_interests"
 */
extern NSString * const facebook_permission_friends_interests;

/**
 * Facebook permission key constant for "user_likes"
 */
extern NSString * const facebook_permission_user_likes;

/**
 * Facebook permission key constant for "friends_likes"
 */
extern NSString * const facebook_permission_friends_likes;

/**
 * Facebook permission key constant for "user_location"
 */
extern NSString * const facebook_permission_user_location;

/**
 * Facebook permission key constant for "friends_location"
 */
extern NSString * const facebook_permission_friends_location;

/** 
 * Facebook permission key constant for "user_notes"
 */
extern NSString * const facebook_permission_user_notes;

/** 
 * Facebook permission key constant for "friends_notes"
 */
extern NSString * const facebook_permission_friends_notes;

/**
 * Facebook permission key constant for "user_photos"
 */
extern NSString * const facebook_permission_user_photos;

/**
 * Facebook permission key constant for "friends_photos"
 */
extern NSString * const facebook_permission_friends_photos;

/**
 * Facebook permission key constant for "user_questions"
 */
extern NSString * const facebook_permission_user_questions;

/**
 * Facebook permission key constant for "friends_questions"
 */
extern NSString * const facebook_permission_friends_questions;

/**
 * Facebook permission key constant for "user_relationships"
 */
extern NSString * const facebook_permission_user_relationships;

/**
 * Facebook permission key constant for "friends_relationships"
 */
extern NSString * const facebook_permission_friends_relationships;

/**
 * Facebook permission key constant for "user_relationship_details"
 */
extern NSString * const facebook_permission_user_relationship_details;

/**
 * Facebook permission key constant for "friends_relationship_details"
 */
extern NSString * const facebook_permission_friends_relationship_details;

/**
 * Facebook permission key constant for "user_religion_politics"
 */
extern NSString * const facebook_permission_user_religion_politics;

/** 
 * Facebook permission key constant for "friends_religion_politics"
 */
extern NSString * const facebook_permission_friends_religion_politics;

/** 
 * Facebook permission key constant for "friends_status"
 */
extern NSString * const facebook_permission_user_status;

/** 
 * Facebook permission key constant for "friends_status"
 */
extern NSString * const facebook_permission_friends_status;

/**
 * Facebook permission key constant for "user_subscriptions"
 */
extern NSString * const facebook_permission_user_subscriptions;

/** 
 * Facebook permission key constant for "friends_subscriptions"
 */
extern NSString * const facebook_permission_friends_subscriptions;

/**
 * Facebook permission key constant for "user_videos"
 */
extern NSString * const facebook_permission_user_videos;

/** 
 * Facebook permission key constant for "friends_videos"
 */
extern NSString * const facebook_permission_friends_videos;

/**
 * Facebook permission key constant for "user_website"
 */
extern NSString * const facebook_permission_user_website;

/**
 * Facebook permission key constant for "friends_website"
 */
extern NSString * const facebook_permission_friends_website;

/**
 * Facebook permission key constant for "user_work_history"
 */
extern NSString * const facebook_permission_user_work_history;

/**
 * Facebook permission key constant for "friends_work_history"
 */
extern NSString * const facebook_permission_friends_work_history;

/** 
 * Facebook permission key constant for "email"
 */
extern NSString * const facebook_permission_email;

/** 
 * Facebook permission key constant for "manage_pages"
 */
extern NSString * const facebook_permission_manage_pages;

/** 
 * Facebook permission key constant for "publish_actions"
 */
extern NSString * const facebook_permission_publish_actions;

/** 
 * Facebook permission key constant for "user_games_activity"
 */
extern NSString * const facebook_permission_user_games_activity;

/** 
 * Facebook permission key constant for "friends_games_activity"
 */
extern NSString * const facebook_permission_friends_games_activity;

/**
 * Facebook permission key constant for "read_friendlists"
 */
extern NSString * const facebook_permission_read_friendlists;

/** 
 * Facebook permission key constant for "read_insights"
 */
extern NSString * const facebook_permission_read_insights;

/**
 * Facebook permission key constant for "read_mailbox"
 */
extern NSString * const facebook_permission_read_mailbox;

/**
 * Facebook permission key constant for "read_requests"
 */
extern NSString * const facebook_permission_read_requests;

/**
 * Facebook permission key constant for "read_stream"
 */
extern NSString * const facebook_permission_read_stream;

/** 
 * Facebook permission key constant for "xmpp_login"
 */
extern NSString * const facebook_permission_xmpp_login;

/**
 * Facebook permission key constant for "ads_management"
 */
extern NSString * const facebook_permission_ads_management;

/**
 * Facebook permission key constant for "create_event"
 */
extern NSString * const facebook_permission_create_event;

/** 
 * Facebook permission key constant for "manage_friendlists"
 */
extern NSString * const facebook_permission_manage_friendlists;

/**
 * Facebook permission key constant for "manage_notifications"
 */
extern NSString * const facebook_permission_manage_notifications;

/**
 * Facebook permission key constant for "user_online_presence"
 */
extern NSString * const facebook_permission_user_online_presence;

/**
 * Facebook permission key constant for "friends_online_presence"
 */
extern NSString * const facebook_permission_friends_online_presence;

/**
 * Facebook permission key constant for "publish_checkins"
 */
extern NSString * const facebook_permission_publish_checkins;

/**
 * Facebook permission key constant for "publish_stream"
 */
extern NSString * const facebook_permission_publish_stream;

/**
 * Facebook permission key constant for "rsvp_event"
 */
extern NSString * const facebook_permission_rsvp_event;

@end