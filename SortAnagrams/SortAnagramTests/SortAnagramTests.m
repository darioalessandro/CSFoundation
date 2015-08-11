//
//  SortAnagramTests.m
//  SortAnagramTests
//
//  Created by Dario on 8/11/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>
#import "SortAnagrams.h"

@interface SortAnagramTests : XCTestCase

@end

@implementation SortAnagramTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
    SortAnagrams * s = [SortAnagrams new];
    NSArray * grouped = [s sort:@[@"baa", @"cca", @"aab", @"acc"]];
    NSArray * expected = @[@[@"baa", @"aab"], @[@"cca", @"acc"]];
    XCTAssertEqualObjects(grouped, expected);
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
