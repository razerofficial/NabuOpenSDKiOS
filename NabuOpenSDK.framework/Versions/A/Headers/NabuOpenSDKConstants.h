//
//  NabuOpenSDKConstants.h
//  NabuOpenSDK
//
//  Copyright (c) 2013 Razer Inc. All rights reserved.
//

#ifndef NabuOpenSDKConstants_Header_h
#define NabuOpenSDKConstants_Header_h

typedef enum : NSUInteger {
    kAuthenticationStatusFailure = 0,
    kAuthenticationStatusSuccess = 1,
    kAuthenticationStatusPermissionDeined = 9999
} AuthenticationStatus;

enum
{
    kOperationFailed = 0,
    kOperationSuccess = 1,
    kOperationPermissionDenied = 9999
};

enum
{
    kOperationQueryFitnessData = 0,
    kOperationQuerySleepData,
    kOperationQueryFitnessHistoryData,
    kOperationRetrieveUserProfile,
    kOperationRefreshAuthenticationToken,
    kOperationSendNotificationToBand,
    kOperationVerifyAuthorizationData,
    kOperationQuerySleepHistoryData,
    kOperationQueryFitnessDataByDate,
    kOperationQueryHiFiveData,
    kOperationQueryPulseData,
    kOperationCreateUpdateMyClipboard,
    kOperationDeleteMyClipboard,
    kOperationQueryMyClipboard,
    kOperationQueryClipboards,
    kOperationQueryBandList
};

// Statuses
#define OPERATION_STATUS                            @"Operation-Status"


// Dictionary Keys
#define RETURNED_OPERATION_KEY                      @"Operation"
#define RETURNED_ERROR_CODE_KEY                     @"ErrorCode"
#define RETURNED_ERROR_MESSAGE_KEY                  @"ErrorMessage"

#define RETURNED_FITNESS_DATA_RECORDS_KEY           @"Fitness Data Records Retrieved"
#define RETURNED_FITNESS_HISTORY_DATA_RECORDS_KEY   @"Fitness History Data Records Retrieved"
#define RETURNED_SLEEP_DATA_RECORDS_KEY             @"Sleep Data Records Retrieved"
#define RETURNED_SLEEP_HISTORY_DATA_RECORDS_KEY     @"Sleep History Data Records Retrieved"
#define RETURNED_HIFIVE_DATA_RECORDS_KEY            @"Hi-Five Data Records Retrieved"
#define RETURNED_PULSE_DATA_RECORDS_KEY             @"Pulse Data Records Retrieved"
#define RETURNED_MY_CLIPBOARD_DATA_RECORD_KEY       @"My Clipboard Data Record Retrieved"
#define RETURNED_CLIPBOARD_DATA_RECORDS_KEY         @"Clipboard Data Records Retrieved"

#define RETURNED_SEND_NOTIFICATION_TO_BAND_KEY      @"Send Notification To Band Status Received"

#define NABU_BAND_ID_KEY                            @"band-id"
#define NABU_MODEL_NAME_KEY                         @"model"
#define NABU_BANDS_KEY                              @"Bands"

// Fitness Data Keys
#define FITNESS_DATA_RECORD_NUMBER_KEY              @"Fitness Data Record %d"
#define FITNESS_DATA_RECORD_TIMESTAMP_KEY           @"record-time"
#define FITNESS_DATA_RECORDED_KEY                   @"data"


// Fitness History Data Keys
#define FITNESS_HISTORY_DATA_RECORD_NUMBER_KEY      @"Fitness History Data Record %d"


// Sleep Data Keys
#define SLEEP_DATA_RECORD_NUMBER_KEY                @"Sleep Data Record %d"
#define SLEEP_DATA_START_TIMESTAMP_KEY              @"start-time"
#define SLEEP_DATA_END_TIMESTAMP_KEY                @"end-time"
#define SLEEP_DATA_RECORDED_KEY                     @"data"


// Clipboard Data Keys
#define MESSAGE_KEY                                 @"message"
#define PUBLIC_DATA_KEY                             @"public-data"
#define PRIVATE_DATA_KEY                            @"private-data"


// User Profile Keys
#define	NABU_USER_NICK_NAME_KEY                     @"Nickname"
#define	NABU_USER_AVATAR_KEY                        @"Avatar"
#define	NABU_USER_BIRTH_YEAR_KEY                    @"BirthYear"
#define NABU_USER_BIRTH_MONTH_KEY                   @"BirthMonth"
#define	NABU_USER_BIRTH_DAY_KEY                     @"BirthDay"
#define	NABU_USER_GENDER_KEY                        @"Gender"
#define NABU_USER_HEIGHT_KEY                        @"height"
#define NABU_USER_WEIGHT_KEY                        @"weight"
#define NABU_USER_UNIT_MEASUREMENT_KEY              @"unit"


// Units
#define NABU_USER_UNIT_METRIC                       @"metric"
#define NABU_USER_UNIT_IMPERIAL                     @"imperial"

// Macro for Nabu OpenSDK Build
#define NABU_OPEN_SDK_RELEASE_BUILD                 1

#endif
