//
//  ViewController.m
//  KVOUI
//
//  Created by Dario on 8/9/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import "ViewController.h"


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self startTimer];
 
}

-(void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context
{
    NSLog(@"From KVO");
    
    if([keyPath isEqualToString:@"name"])
    {
        id oldC = [change objectForKey:NSKeyValueChangeOldKey];
        id newC = [change objectForKey:NSKeyValueChangeNewKey];
        
        NSLog(@"%@ %@", oldC, newC);
        NSLog(@"is main thread %d", [NSThread isMainThread]);
        self.label.text = newC;
    }
}

-(void)startTimer {
    Dog * dog = [Dog new];
    [dog addObserver:self forKeyPath:@"name" options:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld context:NULL];
    self.timer = [NSTimer scheduledTimerWithTimeInterval: 2.0
                                                  target: self
                                                selector:@selector(tick:)
                                                userInfo: dog repeats:TRUE];
}

-(void)tick:(NSTimer *)timer {
    Dog * dog = timer.userInfo;
    dog.name = [NSString stringWithFormat:@"%@", [NSDate date]];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
