//
//  NetmeraPrivacy.h
//  inomeraNetmera
//
//  Created by Karas on 2/3/13.
//  Copyright (c) 2013 /**
 /* Copyright 2012 Inomera Research
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

/**
 * NMPrivacyClass is used as the helper for the privacy of NMContent objects.
 */

typedef enum {
    NMPrivacyPublic,
    NMPrivacyPrivate
} NMPrivacy;

@interface NMPrivacyClass : NSObject

/**
 * Gives the equivalent string for NetmeraPrivacy enum value.
 *
 *  @param privacy NMPrivacy enum value.
 *
 *  @return String value for given NMPrivacy enum type.
 */
+ (NSString *)stringForPrivacy:(NMPrivacy)privacy;

/**
 * Gives the equivalent NetmeraPrivacy enum for the string value.
 *
 *  @param str String representation for privacy.
 *
 *  @return NetmeraPrivacy enum value for given privacy string
 */
+ (NMPrivacy)privacyFromString:(NSString *)str;

@end
