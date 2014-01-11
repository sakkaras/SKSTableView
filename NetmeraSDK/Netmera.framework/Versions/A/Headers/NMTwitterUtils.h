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

/**
 * NMTwitterUtils class is used to perform user operations with a Twitter account. In order to benefit from this class 
 *  properly, you should use Twitter.framework or Social.framework into the project and make necessary configurations 
 *  to be able to access to a Twitter account in Settings application.
 */
@interface NMTwitterUtils : NSObject

/** 
 * Logs on a user with a Twitter account for the application.
 *
 *  @param handler The block to execute when login with a Twitter account is completed.
 */
+ (void)loginWithCompletionHandler:(NMUserResponseHandler)handler;

/** 
 * Logs the user out of the application.
 */
+ (void)logout;

@end
