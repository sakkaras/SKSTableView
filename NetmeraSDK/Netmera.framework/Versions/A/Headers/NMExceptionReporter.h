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
 * NMExceptionReporter class provides a way of tracking exceptions occured on your application during runtime. 
 *  This class internally handles uncaught exceptions which are not catched by try/catch blocks, and reports them
 *  to Netmera server, so that you can track and analyze them. 
 * Moreover, you can send reports about exceptions that you catch in your implementation using class method sendExceptionReport:.
 */

@interface NMExceptionReporter : NSObject

/**
 * Sends the report of the given exception to Netmera.
 *
 *  @param exception Exception object which includes information like error message, stack trace etc.
 */
+ (void)sendExceptionReport:(NSException *)exception;

@end
