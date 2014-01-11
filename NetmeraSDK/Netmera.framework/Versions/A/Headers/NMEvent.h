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

extern NSString * const NMAppOpenEvent;

/**
 * NMEvent class provides a simple to use interface for tracking users' behaviors during application usage.
 *
 *  Netmera SDK tracks following events internally:
 *
 *      - App installation events
 *      - App open events
 *      - App close events
 *      - Time events which track the time that is passed in the application.
 *      - Push notification open events
 *      - Location change events (both on foreground and background)
 *
 *  Moreover, you can create custom events and track users' different behaviors.
 *
 *  @discussion If the default location tracking mechanism of Netmera SDK is used, location change events can be 
 *      fired succesfully on both foreground and background states of the application. This service drastically reduces
 *      battery drain by monitoring only cell tower changes. However, if NMLocationManager class is used to monitor 
 *      location changes, gathering these events will be power-intensive operation. Also, 'location updates' background 
 *      mode is enabled for tracking on background.
 */

@interface NMEvent : NSObject

/**
 * The method which sends related custom event with given key and value.
 *
 *  @param key A string value which uniquely identifies related event.
 *
 *  @param value An NSDictionary object which includes the data related to event.
 *
 *  @discussion Use this method to track behavior of users which could be beneficial for you.
 */
+ (void)sendEventWithKey:(NSString *)key value:(NSDictionary *)value;

@end
