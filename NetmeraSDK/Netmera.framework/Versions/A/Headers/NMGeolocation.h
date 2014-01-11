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

@class CLLocation;

/**
 * NMGeolocation class is used to create geographical objects that hold coordinate values. The instances of this class is 
 *  generally operated in internal of Netmera iOS SDK. You can add location coordinates into the NMContent objects and 
 *  benefit from them on the search queries.
 */

@interface NMGeolocation : NSObject

/** 
 * Latitude value of the NMGeolocation object in degrees.
 */
@property(nonatomic, assign) double latitude;

/** 
 * Longtitude value of the NMGeolocation object in degrees.
 */
@property(nonatomic, assign) double longitude;

/** 
 * Timezone value of the latest location of the device.
 */
@property(nonatomic, assign) double timezone;

/**
 * Initializes the newly allocated NMGeolocation object with the given latitude and longitude coordinates.
 *
 *  @param latitude Latitude in degrees. It must be within the range of (-90, 90).
 *
 *  @param longitude Longitude in degrees. It must be within the range of (-180, 180).
 *
 *  @return An initialized NMGeolocation object.
 */
- (id)initWithLatitude:(double)latitude andLongitude:(double)longitude;

/**
 * Initializes the newly allocated NMGeolocation object with the given CLLocation object.
 *
 *  @param location A CLLocation object that contains the relevant location information.
 *
 *  @return An initialized NMGeolocation object.
 */
- (id)initWithCLLocation:(CLLocation *)location;

/**
 * Sets the latitude value for the NMGeolocation object. It must be within the range of (-90.0, 90.0).
 *
 *  @param latitude Latitude in degrees.
 */
- (void)setLatitude:(double)latitude;

/**
 * Sets the longitude value for the NMGeolocation object. It must be within the range of (-180.0, 180.0).
 *
 *  @param longitude Longitude in degrees.
 */
- (void)setLongitude:(double)longitude;

@end