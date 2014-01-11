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

#import <Foundation/Foundation.h>

typedef void(^NMPopupTriggerResult)(NSMutableArray *triggeredPopups);

typedef void(^NMPopupRegisterResult)(NSError *error);

/**
 * NMPopupManager is the service which manages popup notification flow. It provides means to register to popup notification
 *  service, to retrieve available popups, and to present popup objects on screen.
 * All popup notifications are binded to some event, which means that related popup will be available to retrieve only 
 *  after it's binded event is fired.
 */
@interface NMPopupManager : NSObject

/**
 * This method registers device to popup service with default settings. In this case, popup list is retrieved and updated
 *  from server only at times when application comes to foreground.
 * See registerWithFetchPeriod:error: in order to set popup service a fetch interval.
 *
 *  @param handler The block to execute when registration is completed.
 */
+ (void)registerWithCompletionHandler:(NMPopupRegisterResult)handler;

/**
 * Registers device to popup service with given period interval. If interval is given, popup list is updated from server 
 *  periodically with given interval.
 *
 *  @param interval Time interval which determines the period at which popup list will be updated from server.
 *
 *  @param handler The block to execute when registration is completed.
 */
+ (void)registerWithFetchPeriod:(NSTimeInterval)interval completionHandler:(NMPopupRegisterResult)handler;

/**
 * Unregisters device from registered popup service.
 *
 *  @discussion After you unregister device, calls to getTriggeredPopups and getTriggeredPopupsWithEventKey: methods will
 *      return empty array.
 */
+ (void)unregister;

/**
 * Adds an object as an observer for the given event for triggered popups. When the relevant event fires, the given block
 *  is executed automatically. For an event, you can define as many as objects as an observer.
 *
 *  @param object The object registered as an observer. It is recommended to set a UIViewController object to this parameter
 *      since it is easier to control the triggered popup object in a controller object.
 *
 *  @param key The description of an event which is requested to track for popup objects. If you set nil to this parameter,
 *      your observer listens to all events' fires and your block is executed for all firing events.
 *
 *  @param resultBlock The block to execute when the relevant event fires. It returns the triggered popups binded to the 
 *      given event.
 */
+ (void)addObserver:(id)object forEventKey:(NSString *)key usingBlock:(NMPopupTriggerResult)resultBlock;

/**
 * Removes the object registered as an observer for the regarding event. If a UIViewController object is added as an observer,
 *  it is highly recommended to call this method at least dealloc method of the relevant controller.
 *
 *  @param object The object registered as an observer.
 *
 *  @param key The description of the event which is not requested to listen any more. You should seet nil to this parameter
 *  if you add an observer for all firing events.
 */
+ (void)removeObserver:(id)object forEventKey:(NSString *)key;

/**
 * Method to retrieve popups whose binded events are fired.
 *
 *  @return An array of popup objects which are triggered by some event.
 */
+ (NSMutableArray *)getTriggeredPopups;

/**
 * Method to retrieve popups which are binded to event with given key.
 *
 *  @param key Key of the requested event.
 *
 *  @return An array of popup objects which are triggered by event with given key.
 */
+ (NSMutableArray *)getTriggeredPopupsWithEventKey:(NSString *)key;

/**
 * Presents given popup object on top of current visible view controller. Popup will be shown in a controller with a full 
 *  screen view, using a popping animation.
 *
 *  @param object Popup notification object to be shown.
 */
+ (void)presentPopup:(NMPopupObject*)object;

/**
 * Presents given popup object on top of given view controller. Popup will be shown in a controller with a full screen view,
 *  using a popping animation.
 *
 *  @param object Popup notification object to be shown.
 */
+ (void)presentPopup:(NMPopupObject*)object fromController:(UIViewController*)parentController;

@end
