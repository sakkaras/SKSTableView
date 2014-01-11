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

enum SortOrder {
    SortOrderAscending,
    SortOrderDescending
};

enum CacheType{
    CacheTypeNoCache,
    CacheTypeFromCache,
    CacheTypeFromNetwork,
    CacheTypeFirstCacheThenNetwork,
    CacheTypeFirstNetworkThenCache
};

/**
 * NMService class is used to perform regarding query operations over NMContent objects saved on cloud. This class also
 *  contains the relevant methods configure the settings about query issues.
 */
@interface NMService : NMCore

/*
 * Constant string that shows the key value for querying nearby locations.
 */
extern NSString * const kNearby;

/*
 * Constant string that shows the key value for querying NMContent objects regarding to their creation date.
 */
extern NSString * const kCreateDate;

/*
 * Constant string that shows the key value for querying NMContent objects regarding to their update date.
 */
extern NSString * const kUpdateDate;

/** 
 * Identifier of the NMService object that is equal to the identifier of created NMContent objects.
 */
@property (nonatomic, strong) NSString *objectName __deprecated;

/**
 * Identifier of the NMService object that is equal to the identifier of created NMContent objects.
 */
@property (nonatomic, strong) NSString *identifier;

/** 
 * String value for full-text search over string attributes of a pile of NMContent objects.
 */
@property (nonatomic, strong) NSString *searchText;

/** 
 * Maximum number of the NMContent objects returned from calling query method.
 */
@property (nonatomic, setter=setMax:) int max;

/** 
 * Number of the page that returns the NMContent objects for calling query method.
 *
 *  @discussion If the number of the NMContent objects returned from the calling query method is bigger than 'max' property 
 *      of caller NMService object, contents are divided into the pages. In order to access all the contents, you should 
 *      enumerate all of the pages. The first page is zero.
 */
@property (nonatomic, setter=setPage:) int page;

/** 
 * Path of the requested NMContent object.
 *
 *  @discussion In order to fetch a specific content from cloud, you had to set the path for that content. Now there is 
 *      no need for it. You just should give the path value to the relevant method directly. See getContentAtPath:error: 
 *      or getContentAtPathInBackground:completionHandler:.
 */
@property (nonatomic, strong) NSString *path __deprecated;

/** 
 * Name of the key which holds the value used to sort a pile of contents.
 */
@property (nonatomic, strong) NSString *sortBy;

/** 
 * Enum type of order to use while sorting a pile of contents.
 *
 *  @warning Available enum options for sort order
 *
 *      SortOrderAscending, sorts contents by increasing order
 *
 *      SortOrderDescending, sorts contents by decreasing order
 */
@property (nonatomic) enum SortOrder sortOrder;

/**
 * Initializes the newly allocated NMService object with the specified identifier value.
 *
 *  @param identifier Identifier of the NMService object.
 *
 *  @return An initialized NMService object.
 */
-(id)initWithName:(NSString*)objectName __deprecated;

/**
 * Initializes the newly allocated NMService object with the specified identifier value.
 *
 *  @param identifier Identifier of the NMService object.
 *
 *  @return An initialized NMService object.
 */
- (id)initWithIdentifier:(NSString *)identifier;

/**
 * Fetches the single NMContent object which path is equal to the value set to path property of the caller object.
 *
 *  @param error On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object 
 *      containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 *  @return The NMContent object requested for the setting path.
 *
 *  @discussion The relevant path value is obtained from 'Content Browser' segment of your application on Netmera website.
 */
- (id)get:(NSError **)error __deprecated;

/**
 * Fetches the single NMContent object which path is equal to the value set to path property of the caller object on the 
 *  background thread.
 *
 *  @param handler The block to execute when fetch of the content is completed.
 *
 *  @discussion As background methods does not block your main thread, it is recommended to use 
 *      getContentAtPathInBackground:completionHandler: over get:.
 */
- (void)getInBackgroundWithCompletionHandler:(void(^)(NMContent *content, NSError *error))handler __deprecated;

/**
 * Fetches the single NMContent object which path is equal to the value set to path parameter.
 *
 *  @param path The unique string id for the requested NMContent object.
 *
 *  @param error On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object 
 *      containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 *  @return The NMContent object requested for the relevant path.
 *
 *  @discussion The relevant path value is obtained from 'Content Browser' segment of your application on Netmera website.
 */
- (id)getContentAtPath:(NSString *)path error:(NSError **)error;

/**
 * Fetches the single NMContent object which path is equal to the value set to path parameter on the background thread.
 *
 *  @param path The unique string id for the requested NMContent object.
 *
 *  @param handler The block to execute when fetch of the content is completed.
 *
 *  @discussion As background methods does not block your main thread, it is recommended to use 
 *      getContentAtPathInBackground:completionHandler: over getContentAtPath:error:.
 */
- (void)getContentAtPathInBackground:(NSString *)path completionHandler:(void(^)(id content, NSError *error))handler;

/**
 * Fetches a list of NMContent objects with the given path list.
 *
 *  @param pathList The array of the paths for requested NMContent objects.
 *
 *  @param error On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object 
 *      containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 *  @return The list of the NMContent objects for the requested path list.
 *
 *  @warning Default values for the 'max' property is 10 and 'page' property 0. This means this method returns 10 result 
 *  in each page. It skips page * max in each iteration.
 *
 *  @discussion The relevant path values are obtained from 'Content Browser' segment of your application on Netmera website.
 */
- (NSArray *)getContentsAtPaths:(NSArray *)pathList error:(NSError **)error;

/**
 * Fetches a list of NMContent objects with the given path list.
 *
 *  @param pathList The array of the paths for requested NMContent objects.
 *
 *  @param handler The block to execute when fetch of the content(s) is completed.
 *
 *  @warning Default values for the 'max' property is 10 and 'page' property 0. This means this method returns 10 result 
 *      in each page. It skips page * max in each iteration.
 *
 *  @discussion As background methods does not block your main thread, it is recommended to use 
 *      getContentsAtPathsInBackground:completionHandler: over getContentsAtPaths:error:.
 */
- (void)getContentsAtPathsInBackground:(NSArray *)pathList completionHandler:(void(^)(NSArray *contentArray, NSError *error))handler;

/**
 * Fetches a list of NMContent objects matching the search query.
 *
 *  @param error On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object 
 *      containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 *  @warning Default values for the 'max' property is 10 and 'page' property 0. This means this method returns 10 result 
 *  in each page. It skips page * max in each iteration.
 */
- (NSArray *)search:(NSError **)error __deprecated;

/**
 * Fetches a list of NMContent objects matching the search query.
 *
 *  @param error On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object 
 *      containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 *  @warning Default values for the 'max' property is 10 and 'page' property 0. This means this method returns 10 result 
 *  in each page. It skips page * max in each iteration.
 */
- (NSArray *)searchContentsWithError:(NSError **)error;

/**
 * Fetches a list of NMContent objects matching the search query on the background thread.
 *
 *  @param handler The block to execute when fetch of the content(s) is completed.
 *
 *  @warning Default values for the 'max' property is 10 and 'page' property 0. This means this method returns 10 result 
 *      in each page. It skips page * max in each iteration.
 *
 *  @discussion As background methods does not block your main thread, it is recommended to use 
 *      searchContentsInBackgroundWithCompletionHandler: over search:.
 */
- (void)searchInBackgroundWithCompletionHandler:(void(^)(NSArray *contentArray, NSError *error))handler __deprecated;

/**
 * Fetches a list of NMContent objects matching the search query on the background thread.
 *
 *  @param handler The block to execute when fetch of the content(s) is completed.
 *
 *  @warning Default values for the 'max' property is 10 and 'page' property 0. This means this method returns 10 result 
 *      in each page. It skips page * max in each iteration.
 *
 *  @discussion As background methods does not block your main thread, it is recommended to use 
 *      searchContentsInBackgroundWithCompletionHandler: over searchContentsWithError:.
 */
- (void)searchContentsInBackgroundWithCompletionHandler:(void(^)(NSArray *contentArray, NSError *error))handler;

/**
 * Returns the total number of the NMContent objects matching the search query.
 *
 *  @param error On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object
 *      containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 *  @return The number of the contents for the relevant query.
 */
- (long)count:(NSError**)error __deprecated;

/**
 * Returns the total number of the NMContent objects matching the search query.
 *
 *  @param error On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object 
 *      containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 *  @return The number of the contents for the relevant query.
 */
- (long)countContentsWithError:(NSError **)error;

/**
 * Returns the total number of the NMContent objects matching the search query on the background thread.
 *
 *  @param handler The block to execute when fetch of the count of the content(s) is completed.
 *
 *  @discussion As background methods does not block your main thread, it is recommended to use 
 *      countContentsInBackgroundWithCompletionHandler: over count:.
 */
- (void)countInBackgroundWithCompletionHandler:(void(^)(NSNumber *count, NSError *error))handler __deprecated;

/**
 * Returns the total number of the NMContent objects matching the search query on the background thread.
 *
 *  @param handler The block to execute when fetch of the count of the content(s) is completed.
 *
 *  @discussion As background methods does not block your main thread, it is recommended to use 
 *      countContentsInBackgroundWithCompletionHandler: over countContentsWithError:.
 */
- (void)countContentsInBackgroundWithCompletionHandler:(void(^)(long, NSError *error))handler;

/**
 * Fetches a list of NMContent objects which are placed within the range of the given distance around the specified center 
 *  location.
 *
 *  @param startLocation Center location to search the contents around it.
 *
 *  @param distance Radius of the search area.
 *
 *  @param locationSearchField Alphanumeric string that represents the key value which contains the location data.
 *
 *  @param error On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object 
 *      containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 *  @return The list of the content(s) which meet the location search criterias.
 */
- (NSArray *)circleSearchWithStartLocation:(NMGeolocation *)startLocation andDistance:(double)distance andlocationSearchField:(NSString *)locationSearchField withError:(NSError **)error __deprecated;

/**
 * Fetches a list of NMContent objects which are placed within the range of the given distance around the specified center 
 *  location.
 *
 *  @param centerLocation Center location to search the contents around it.
 *
 *  @param radius Radius of the search area.
 *
 *  @param key Alphanumeric string that represents the key value which contains the location data.
 *
 *  @param error On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object 
 *      containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 *  @return The list of the content(s) located within the given area.
 */
- (NSArray *)circleSearchWithLocation:(NMGeolocation *)centerLocation radius:(double)radius key:(NSString *)key error:(NSError **)error;

/**
 * Fetches a list of NMContent objects which are placed within the range of the given distance around the specified center 
 *  location on the background thread.
 *
 *  @param startLocation Center location to search the contents around it.
 *
 *  @param distance Radius of the search area.
 *
 *  @param locationSearchField Alphanumeric string that represents the key value which contains the location data.
 *
 *  @param handler The block to execute when fetch of the content(s) within the circle area is completed.
 *
 *  @discussion As background methods does not block your main thread, it is recommended to use 
 *      circleSearchInBackgroundWithLocation:radius:key:completionHandler over
 *      circleSearchWithStartLocation:andDistance:andLocationSearchField:error.
 */
- (void)circleSearchInBackgroundStartLocation:(NMGeolocation *)startLocation distance:(double)distance locationSearchField:(NSString *)alocationSearchField completionHandler:(void(^)(NSArray *contentArray, NSError *error))handler  __deprecated;

/**
 * Fetches a list of NMContent objects which are placed within the range of the given distance around the specified center 
 *  location on the background thread.
 *
 *  @param centerLocation Center location to search the contents around it.
 *
 *  @param radius Radius of the search area.
 *
 *  @param key Alphanumeric string that represents the key value which contains the location data.
 *
 *  @param handler The block to execute when fetch of the content(s) within the circle area is completed.
 *
 *  @discussion As background methods does not block your main thread, it is recommended to use 
 *      circleSearchInBackgroundWithLocation:radius:key:completionHandler over 
 *      circleSearchWithStartLocation:andDistance:andLocationSearchField:error.
 */
- (void)circleSearchInBackgroundWithLocation:(NMGeolocation *)centerLocation radius:(double)radius key:(NSString *)key completionHandler:(void(^)(NSArray *contentArray, NSError *error))handler;

/**
 * Fetches a list of NMContent objects which are placed within the box area created with the given location coordinates.
 *
 *  @param firstPoint Any of the locations which is one of the corners of the box area.
 *
 *  @param secondPoint Diagonal location of the one given as the firstPoint paramater.
 *
 *  @param locationSearchField The name of the key which value is the location data.
 *
 *  @param error On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object 
 *      containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 *  @return The list of the content(s) located within the given area.
 */
-(NSArray*)boxSearchWithFirstLocation:(NMGeolocation*)firstPoint andSecondLocation:(NMGeolocation*)secondPoint andlocationSearchField:(NSString*)locationSearchField withError:(NSError**)error __deprecated;

/**
 * Fetches a list of NMContent objects which are placed within the box area created with the given location coordinates.
 *
 *  @param startLocation Any of the locations which is one of the corners of the box area.
 *
 *  @param diagonalLocation Diagonal location of the one given as the startLocation paramater.
 *
 *  @param key The name of the key which value is the location data.
 *
 *  @param error On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object 
 *      containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 *  @return The list of the content(s) located within the given area.
 */
- (NSArray *)boxSearchWithStartLocation:(NMGeolocation *)startLocation diagonalLocation:(NMGeolocation *)diagonalLocation key:(NSString *)key error:(NSError **)error;

/**
 * Fetches a list of NMContent objects which are placed within the box area created with the given location coordinates on the 
 *  background thread.
 *
 *  @param firstPoint Any of the locations which is one of the corners of the box area.
 *
 *  @param secondPoint Diagonal location of the one given as the firstPoint paramater.
 *
 *  @param locationSearchField The name of the key which value is the location data.
 *
 *  @param handler The block to execute when fetch of the content(s) within the box area is completed.
 *
 *  @discussion As background methods does not block your main thread, it is recommended to use 
 *      boxSearchInBackgroundWithStartLocation:diagonalLocation:key:completionHandler: over 
 *      boxSearchWithFirstLocation:andSecondLocation:andlocationSearchField:withError:.
 */
-(void)boxSearchInBackgroundFirstLocation:(NMGeolocation*)firstPoint secondLocation:(NMGeolocation*)secondPoint locationSearchField:(NSString*)alocationSearchField completionHandler:(void(^)(NSArray *contentArray, NSError *error))handler __deprecated;

/**
 * Fetches a list of NMContent objects which are placed within the box area created with the given location coordinates on the 
 *  background thread.
 *
 *  @param startLocation Any of the locations which is one of the corners of the box area.
 *
 *  @param diagonalLocation Diagonal location of the one given as the firstPoint paramater.
 *
 *  @param key The name of the key which value is the location data.
 *
 *  @param handler The block to execute when fetch of the content(s) within the box area is completed.
 *
 *  @discussion As background methods does not block your main thread, it is recommended to use 
 *      boxSearchInBackgroundWithStartLocation:diagonalLocation:key:completionHandler: over 
 *      boxSearchWithStartLocation:diagonalLocation:key:error:.
 */
- (void)boxSearchInBackgroundWithStartLocation:(NMGeolocation *)startLocation diagonalLocation:(NMGeolocation *)diagonalLocation key:(NSString *)key completionHandler:(void(^)(NSArray *contentArray, NSError *error))handler;

/**
 * Adds a value for full-text search over string attributes of a pile of NMContent objects into the query.
 *
 *  @param searchText String value for full-text search.
 */
- (void)addSearchText:(NSString*)searchText __deprecated;

/**
 * This is used to get the contents of the logged user.
 *
 *  @param user Current logged user.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereOwnerEqual:(NMUser *)user __deprecated;

/**
 * This is used to get the contents of the logged user.
 *
 *  @param user Current logged user.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereEqualToOwner:(NMUser *)user;

/**
 * Adds an option into the query which filters the contents which values of given key are equal to the given value.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Object value associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereEqualWithKey:(NSString *)key andValue:(id)value __deprecated;

/**
 * Adds an option into the query which filters the contents which values of given key are equal to the given value.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Object value associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereEqualToValue:(id)value forKey:(NSString *)key;

/*
 * Adds an option into the query which filters the contents which values of given key are equal to the given value.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Object value associated with the specified key to filter the NMContent objects.
 *
 *  @param flag The boolean value that determines whether value is case sensitive or not while filtering the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereEqualWithKey:(NSString *)key value:(id)value caseInsensitive:(BOOL)flag __deprecated;

/*
 * Adds an option into the query which filters the contents which values of given key are equal to the given value.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Object value associated with the specified key to filter the NMContent objects.
 *
 *  @param flag The boolean value that determines whether value is case sensitive or not while filtering the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereEqualToValue:(id)value forKey:(NSString *)key caseInsensitive:(BOOL)flag;

/**
 * Adds an option into the query which filters the contents which values of given key are greater than the given value.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Object value associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereGreaterThanWithKey:(NSString *)key andValue:(id)value __deprecated;

/**
 * Adds an option into the query which filters the contents which values of given key are greater than the given value.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Object value associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereGreaterThanValue:(id)value forKey:(NSString *)key;

/**
 * Adds an option into the query which filters the contents which values of given key are less than the given value.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Object value associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereLessThanWithKey:(NSString *)key andValue:(id)value __deprecated;

/**
 * Adds an option into the query which filters the contents which values of given key are less than the given value.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Object value associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereLessThanValue:(id)value forKey:(NSString *)key;

/**
 * Adds an option into the query which filters the contents which values of given key are not equal to the given value.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Object value associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereNotEqualWithKey:(NSString *)key andValue:(id)value __deprecated;

/**
 * Adds an option into the query which filters the contents which values of given key are not equal to the given value.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Object value associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereNotEqualToValue:(id)value forKey:(NSString *)key;

/**
 * Adds an option into the query which filters the contents which values of given key are greater than or equal to the
 *  given value.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Object value associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereGreatherThanOrEqualWithKey:(NSString *)key andValue:(id)value __deprecated;

/**
 * Adds an option into the query which filters the contents which values of given key are greater than or equal to the 
 *  given value.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Object value associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereGreatherThanOrEqualToValue:(id)value forKey:(NSString *)key;

/**
 * Adds an option into the query which filters the contents which values of given key are less than or equal to the 
 *  given value.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Object value associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereLessThanOrEqualWithKey:(NSString *)key andValue:(id)value __deprecated;

/**
 * Adds an option into the query which filters the contents which values of given key are less than or equal to the 
 *  given value.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Object value associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereLessThanOrEqualToValue:(id)value forKey:(NSString *)key;

/**
 * Adds an option into the query which filters the contents which contain the given key or not.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value The boolean value to check the existance of the given key or not. If the value is YES then this filters the 
 *      contents for the existance of the key; otherwise, it checks for the non-existance of the given key.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereExistsWithKey:(NSString *)key andValue:(BOOL)value __deprecated;

/**
 * Adds an option into the query which filters the contents which contain the given key or not.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value The boolean value to check the existance of the given key or not. If the value is YES then this filters the 
 *      contents for the existance of the key; otherwise, it checks for the non-existance of the given key.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereExist:(BOOL)value forKey:(NSString *)key;

/**
 * Adds an option into the query which filters the contents which values of given key match the given regex.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Regex associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereMatchesWithKey:(NSString *)key andRegex:(NSString *)regex __deprecated;

/**
 * Adds an option into the query which filters the contents which values of given key match the given regex.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Regex associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereMatchWithRegex:(NSString *)regex forKey:(NSString *)key;

/**
 * Adds an option into the query which filters the contents which values of given key match the given regex.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Regex associated with the specified key to filter the NMContent objects.
 *
 *  @param flag The boolean value that determines whether regex is case sensitive or not while filtering the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereMatchesWithKey:(NSString *)key regex:(NSString *)regex caseInsensitive:(BOOL)flag __deprecated;

/**
 * Adds an option into the query which filters the contents which values of given key match the given regex.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Regex associated with the specified key to filter the NMContent objects.
 *
 *  @param flag The boolean value that determines whether regex is case sensitive or not while filtering the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereMatchWithRegex:(NSString *)regex forKey:(NSString *)key caseInsensitive:(BOOL)flag;

/**
 * Adds an option into the query which filters the contents which values of given key begin with the given prefix.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Prefix associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereStartsWithKey:(NSString *)key andPrefix:(id)prefix __deprecated;

/**
 * Adds an option into the query which filters the contents which values of given key begin with the given prefix.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Prefix associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereStartWithValue:(NSString *)prefix forKey:(NSString *)key;

/**
 * Adds an option into the query which filters the contents which values of given key begin with the given prefix.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Prefix associated with the specified key to filter the NMContent objects.
 *
 *  @param flag The boolean value that determines whether the given prefix is case sensitive or not while filtering 
 *  the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereStartsWithKey:(NSString *)key prefix:(id)prefix caseInsensitive:(BOOL)flag __deprecated;

/**
 * Adds an option into the query which filters the contents which values of given key begin with the given prefix.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Prefix associated with the specified key to filter the NMContent objects.
 *
 *  @param flag The boolean value that determines whether the given prefix is case sensitive or not while filtering 
 *      the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereStartWithValue:(NSString *)prefix forKey:(NSString *)key caseInsensitive:(BOOL)flag;

/**
 * Adds an option into the query which filters the contents which values of given key end with the given suffix.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Suffix associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereEndsWithKey:(NSString *)key andSuffix:(id)suffix __deprecated;

/**
 * Adds an option into the query which filters the contents which values of given key end with the given suffix.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Suffix associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereEndWithValue:(NSString *)suffix forKey:(NSString *)key;

/**
 * Adds an option into the query which filters the contents which values of given key end with the given suffix.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Suffix associated with the specified key to filter the NMContent objects.
 *
 *  @param flag The boolean value that determines whether the given suffix is case sensitive or not while filtering 
 *      the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereEndsWithKey:(NSString *)key suffix:(id)suffix caseInsensitive:(BOOL)flag __deprecated;

/**
 * Adds an option into the query which filters the contents which values of given key end with the given suffix.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param value Suffix associated with the specified key to filter the NMContent objects.
 *
 *  @param flag The boolean value that determines whether the given suffix is case sensitive or not while filtering 
 *      the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereEndWithValue:(NSString *)suffix forKey:(NSString *)key caseInsensitive:(BOOL)flag;

/**
 * Adds an option into the query where filters the contents which values of the given key match any of the values in the 
 *  given collection.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param values The array of values associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereContainedInWithKey:(NSString *)key andValues:(NSArray *)values __deprecated;

/**
 * Adds an option into the query where filters the contents which values of the given key match any of the values in 
 *  the given collection.
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param values The array of values associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereContainAnyValueIn:(NSArray *)values forKey:(NSString *)key;

/**
 * Adds an option into the query where filters the contents which values of the given key match all of the values in 
 *  the given collection.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param values The array of values associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereAllContainedInWithKey:(NSString *)key andValues:(NSArray *)values __deprecated;

/**
 * Adds an option into the query where filters the contents which values of the given key match all of the values in 
 *  the given collection.
 *
 *  @param key Alphanumeric string that represents the key value for the query.
 *
 *  @param values The array of values associated with the specified key to filter the NMContent objects.
 *
 *  @return Caller NMService object.
 */
- (NMService *)whereContainAllValuesIn:(NSArray *)values forKey:(NSString *)key;

/**
 * Returns the single query formed by merging all query options.
 *
 *  @return NSString representation of the list of the query options added as a search criteria.
 */
- (NSString*)getCustomCondition;

/**
 * Fetches a list of NMUser objects matching the search query.
 *
 *  @param error On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object 
 *      containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 *  @return The list of the NMUser object(s) for the specified query.
 */
- (NSArray *)searchUser:(NSError **)error __deprecated;

/**
 * Fetches a list of NMUser objects matching the search query.
 *
 *  @param error On input, a pointer to an error object. If an error occurs, this pointer is set to an actual error object 
 *      containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 *  @return The list of the NMUser object(s) for the specified query.
 */
- (NSArray *)getUsersWithError:(NSError **)error;

#pragma mark - Caching

/**
 * Returns the type of the Cache to use while searching.
 *
 *  @return Current cache type for search methods.
 *
 *  @warning Available enum options to set cache type:
 *
 *      CacheTypeNoCache, Queries does not add and retrieve results to cache.
 *
 *      CacheTypeFromCache, Queries retrieve results from the cache.
 *
 *      CacheTypeFromNetwork, Queries retrieve results from the network and add results into the cache.
 *
 *      CacheTypeFirstCacheThenNetwork, Queries first tries to get results from cache, if it cannot find then
 *          tries to get from network.
 *
 *      CacheTypeFirstNetworkThenCache, Queries first tries to get results from network, if it cannot find
 *          then tries to get from cache.
 */
+ (enum CacheType)cacheType;

/**
 * Sets the enum value for cache type of search methods.
 *
 *  @param cacheType The enum value for the cache type.
 *
 *  @warning Available enum options to set cache type:
 *
 *      CacheTypeNoCache, Queries does not add and retrieve results to cache.
 *
 *      CacheTypeFromCache, Queries retrieve results from the cache.
 *
 *      CacheTypeFromNetwork, Queries retrieve results from the network and add results into the cache.
 *
 *      CacheTypeFirstCacheThenNetwork, Queries first tries to get results from cache, if it cannot find then
 *          tries to get from network.
 *
 *      CacheTypeFirstNetworkThenCache, Queries first tries to get results from network, if it cannot find
 *          then tries to get from cache.
 */
+ (void)setCacheType:(enum CacheType)cacheType;

/**
 * Returns the interval value when the contents will be deleted from the cache.
 *  
 *  @return returns the cache expiration value.
 */
+ (NSTimeInterval)cacheExpirationInterval;

/**
 * Sets the expiration value for the time interval when the cached contents will be deleted.
 *
 *  @param interval The expiration value for cache mechanism.
 */
+ (void)setCacheExpirationInterval:(NSTimeInterval)interval;

/**
 * Removes all data saved in the cache.
 */
+ (void)clearCache;

@end