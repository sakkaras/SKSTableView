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

#import <Netmera/Netmera.h>

/**
 * NMPopupObject class stores related data of a pop up notification. It is subclassed from NMRichPushObject
 */
@interface NMPopupObject : NMRichPushObject

/**
 * Key of the event which triggers the popup after it(event) is fired.
 *
 * Apart from custom events, You can also bind your pop up notifications to following events which are fired
 *  automatically by SDK:
 *
 *      - NMAppOpenEvent
 */
@property (nonatomic, strong) NSString* bindedEvent;

/**
 * This method can be used if you want to customize pop up notification view. Method takes a web view, and loads content of
 *  the popup notification to web view. Using this method, you can show your popups in views with any size.
 *
 *  @param webView UIWebView object which will show popup.
 */
- (void)presentInWebView:(UIWebView*)webView;

@end
