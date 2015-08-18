//
//  QueueWithMin.h
//  3.2
//
//  Created by Dario on 8/17/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface QueueWithMin : NSObject

-(NSNumber *)min;
-(NSNumber *)max;
-(NSNumber *)pop;
-(void)push:(NSNumber *)number;


@end
