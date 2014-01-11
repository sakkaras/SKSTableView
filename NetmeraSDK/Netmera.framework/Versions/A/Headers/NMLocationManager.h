//
//  NMLocationManager.h
//  inomeraNetmera
//
//  Created by Serhat Sarı on 1/31/13.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreTelephony/CTCarrier.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>

/**
 * NMLocationManager is a service that enables developers to location tracking for push notifications. If you want to
 *  send locational push notifications and if you use this service you do not need to track device locations. This
 *  service automatically updates device location. When your users get closer to specific location, you can send 
 *  automated push messages to them in certain time interval.
 * It is recommended to use this class when high-precision location data is required. However, if just regular
 *  position updates are enough for the application, Netmera SDK default location tracking mechanism is more than 
 *  enough; otherwise, the parameters of this service should be configured in a way that minimizes its impact on battery
 *  life.
 */

@interface NMLocationManager : NSObject

/**
 * The desired location accuracy. The location service will try its best to achieve
 *  your desired accuracy. However, it is not guaranteed. To optimize
 *  power performance, be sure to specify an appropriate accuracy for your usage scenario (eg,
 *  use a large accuracy value when only a coarse location is needed). Use kCLLocationAccuracyBest to
 *  achieve the best possible accuracy. Use kCLLocationAccuracyBestForNavigation for navigation.
 *  By default, kCLLocationAccuracyHundredMeters is used.
 *
 *  @return Current desiredAccuracy of location service.
 */
+ (CLLocationAccuracy)desiredAccuracy;

/**
 * Sets the desiredAccuracy option of location manager.
 *
 *  @param accuracy Enum value for desired accuracy.
 */
+ (void)setDesiredAccuracy:(CLLocationAccuracy)accuracy;

/**
 * Specifies the minimum update distance in meters. Client will not be notified of movements of less
 *  than the stated value, unless the accuracy has improved. Pass in kCLDistanceFilterNone to be
 *  notified of all movements. By default, 10 meters is used.
 *
 *  @return Current distanceFilter of location service.
 */
+ (CLLocationDistance)distanceFilter;

/**
 * Sets the distanceFilter option of location manager.
 *
 *  @param distance Value in meters for distance filter.
 */
+ (void)setDistanceFilter:(CLLocationDistance)distance;

/**
 * Starts tracking the position of the device.
 */
+ (void)startLocationTracking;

/**
 * Stops tracking the position of the device.
 */
+ (void)stopLocationTracking;

/**
 * Last location of the device.
 */
+ (CLLocation *)recentLocation;

@end
