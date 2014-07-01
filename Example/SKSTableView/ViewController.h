//
//  ViewController.h
//  SKSTableView
//
//  Created by Sakkaras on 26/12/13.
//  Copyright (c) 2013 Sakkaras. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SKSTableView.h"

@interface ViewController : UIViewController <SKSTableViewDelegate>

@property (nonatomic, weak) IBOutlet SKSTableView *tableView;

@end
