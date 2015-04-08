//
//  NabuSleepTrackerData.h
//  RazerSynapseSDK
//
//  Created by Razer on 11/3/14.
//  Copyright (c) 2014 Razer. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @class NabuSleepTracker
 @abstract A class that defines a list of Nabu fitness data within a specified time
 @discussion
    startTime   - start time of list of fitness data in Unix timestamp
    endTime     - end time of list of fitness data in Unix timestamp
    sleepData   - list of sleep data
 @updated 2014-03-11
 */

@interface NabuSleepTracker : NSObject

@property (copy, nonatomic) NSMutableArray *sleepDataArray;
@property (copy, nonatomic) NSMutableArray *sleepHistoryDataArray;

@end

/*!
 @class NabuSleepTrackerData
 @abstract  A class that defines the Nabu Sleep Tracker Data
 @discussion
 @updated 2014-03-11
 */

@interface NabuSleepTrackerData : NSObject

@property (nonatomic) NSString *bandId;
@property (nonatomic) NSString *modelName;

@property (nonatomic) double startTime;
@property (nonatomic) double endTime;

@property (nonatomic) NSString *sleepData;
@property (nonatomic) NSString *sleepDataInMinutes;


@end


/*!
 @class NabuSleepHistoryData
 @abstract  A class that defines the Nabu Sleep History Data
 @discussion
 @updated 2014-03-11
 */

@interface NabuSleepHistoryData : NSObject

@property (nonatomic) NSString *bandId;
@property (nonatomic) NSString *modelName;

@property (nonatomic) double numOfDays;

@property (nonatomic) double sleepHistoryRecordDate;
@property (nonatomic) NSString *efficiency;
@property (nonatomic) NSString *good;
@property (nonatomic) NSString *bad;



@end
