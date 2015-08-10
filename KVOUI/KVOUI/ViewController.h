//
//  ViewController.h
//  KVOUI
//
//  Created by Dario on 8/9/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Dog.h"

@interface ViewController : UIViewController 

@property (weak, nonatomic) IBOutlet UILabel *label;
@property (strong, nonatomic) NSTimer * timer;

@end

