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

@class NMPushObject;
@class NMRichPushObject;

/** 
 * NMPushInboxListDelegate is the protocol, which notifies delegate object whether push inbox list was loaded or failed.
 */

@protocol NMPushInboxListDelegate <NSObject>

/** 
 * This method is notified when push inbox list was loaded correctly.
 */
- (void)pushInboxListDidLoad;

/**
 * This method is notified when push inbox list was not loaded correctly. The error that causes the fail of loading the push 
 *  inbox list is also reported.
 *
 *  @param error Error of loading the push inbox list uncorrectly.
 */
- (void)pushInboxListDidFailLoad:(NSError *)error;

@end

/** 
 * NMPushInboxList is the class, which stores the rich push notifications that are shown in push inbox as a list. It also 
 *  represents an interface for performing some operations upon this list.
 */
@interface NMPushInboxList : NSObject

/**
 * The boolean value regarding whether new rich push notification is received or not.
 */
@property (nonatomic, assign) BOOL newPushReceived;

/**
 * The object that acts as the delegate of the receiving NMPushInboxList.
 *
 *  @discussion The delegate must adopt the NMPushInboxListDelegate protocol.
 */
@property (nonatomic, assign) id<NMPushInboxListDelegate> delegate;

/** 
 * Returns the list that includes the rich push notifications that are shown in push inbox.
 *
 *  @return List of the rich push notifications
 */
+ (NMPushInboxList *)sharedList;

/** 
 * Returns the NMRichPushObject, which is taken place before the current rich push object in the push inbox list.
 *
 *  @param NMRichPushObject, which is after the requested rich push object.
 *
 *  @return NMRichPushObject before the object given as parameter
 */
- (NMRichPushObject *)richPushObjectBeforeObject:(NMPushObject *)object;

/**
 * Returns the NMRichPushObject, which is taken place after the current rich push object in the push inbox list.
 *
 *  @param NMRichPushObject, which is before the requested rich push object.
 *
 *  @return NMRichPushObject after the object given as parameter.
 */
- (NMRichPushObject*)richPushObjectAfterObject:(NMPushObject*)object;

/** 
 * Returns the recently added NMPushObject.
 *
 *  @return Latest NMPushObject in push inbox list.
 */
- (NMPushObject *)recentPushObject;

/** 
 * Returns the NMPushObject, which is taken place in the given index of the push inbox list.
 *
 *  @param index Value of the NMPushObject that is wanted to get.
 *
 *  @return NMPushObject at requested index.
 */
- (NMPushObject *)pushObjectAtIndex:(NSInteger)index;

/** 
 * Returns the index of the NMPushObject in the push inbox list.
 *
 *  @param obj NMPushObject of which the index is wanted to get.
 *
 *  @return Index value of the requested NMPushObject.
 */
- (NSInteger)indexOfPushObject:(NMPushObject *)obj;

/** 
 * Removes the NMPushObject at given index from the push inbox list.
 *
 *  @param index Value of the NMPushObject, which is wanted to remove.
 *
 *  @return The boolean value regarding whether the requested push object is removed or not.
 */
- (BOOL)removePushObjectAtIndex:(NSInteger)index;

/** 
 * Removes the NMPushObject(s) at the indexes in given set from the push inbox list.
 *
 *  @param indexes NSIndexSet object, which includes the indexes of NMPushObject(s), which are wanted to remove.
 *
 *  @return The boolean value regarding whether the requested push objects are removed or not.
 */
- (BOOL)removePushObjectsAtIndexes:(NSIndexSet *)indexes;

/**
 * Marks the rich push objects, which are taken place at the indexes of giving index set in the push inbox list as read.
 *
 *  @param indexSet Indexes of the rich push objects to mark as read.
 *
 *  @return The boolean value that indicates if rich push objects at indexes of index set are marked as read or not.
*/
- (BOOL)markAsReadPushObjectsAtIndexes:(NSIndexSet *)indexSet;

/**
 * Marks the giving rich push object as read.
 *
 *  @param object The rich push object to mark as read.
 *
 *  @return The boolean value that indicates if rich push object is marked as read or not.
 */
- (BOOL)markAsReadPushObject:(NMPushObject *)object;

/**
 * Marks the rich push object, which is taken place at the giving index in the push inbox list as read.
 *
 *  @param index Index of the rich push object to mark as read
 *
 *  @return The boolean value that indicates if rich push object at index is marked as read or not.
 */
- (BOOL)markAsReadPushObjectAtIndex:(NSInteger)index;

/**
 * Marks the rich push objects, which are taken place at the indexes of giving index set in the push inbox list as unread.
 *
 *  @param indexSet Indexes of the rich push objects to mark as unread.
 *
 *  @return The boolean value that indicates if rich push objects at indexes of index set are marked as unread or not.
 */
- (BOOL)markAsUnreadPushObjectsAtIndexes:(NSIndexSet *)indexSet;

/**
 * Marks the rich push object, which are taken place at the index in the push inbox list as unread.
 *
 *  @param index Index of the rich push object to mark as unread.
 *
 *  @return The boolean value that indicates if rich push object at index is marked as unread or not.
 */
- (BOOL)markAsUnreadPushObjectAtIndex:(NSInteger)index;

/**
 * Fetches all read and unread rich pushes recorded for the device in the server.
 */
- (void)fetchPushInboxList;

/** 
 * Insert the given NMPushObject into the push inbox list.
 *
 *  @param NMPushObject, which is wanted to add to the push inbox list.
 *
 *  @return The boolean value regarding whether the given push object is added to the push inbox list.
 */
- (BOOL)addPushObject:(NMPushObject *)object;

/** 
 * Returns the number of the rich push objects, which are taken place in the push inbox list.
 *
 *  @return The total number of rich push notifications in the push inbox list.
 */
- (NSInteger)count;

@end
