//
//  Constants.h
//  IntegratedInspectionSystem
//    ___  _____   ______  __ _   _________
//   / _ \/ __/ | / / __ \/ /| | / / __/ _ \
//  / , _/ _/ | |/ / /_/ / /_| |/ / _// , _/
// /_/|_/___/ |___/\____/____/___/___/_/|_|
//  Created by 杨付华 on 2017/2/27.
//  Copyright © 2017年 KEENTEAM. All rights reserved.
//

#ifndef Constants_h
#define Constants_h
//屏幕宽度
#define kWidth [UIScreen mainScreen].bounds.size.width
//屏幕高度
#define kHeight [UIScreen mainScreen].bounds.size.height
//是否为空或是[NSNull null]
#define NotNilAndNull(_ref)  (((_ref) != nil) && (![(_ref) isEqual:[NSNull null]]))
#define IsNilOrNull(_ref)   (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]))
//字符串是否为空
#define IsStrEmpty(_ref)    (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) ||([(_ref)isEqualToString:@""]))
//数组是否为空
#define IsArrEmpty(_ref)    (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) ||([(_ref) count] == 0))

//16>10
#define UIColorFromHex(hex) [UIColor colorWithRed:((float)((hex & 0xFF0000) >> 16))/255.0 green:((float)((hex & 0xFF00) >> 8))/255.0 blue:((float)(hex & 0xFF))/255.0 alpha:1.0]
//rgb颜色转换
#define is_IOS_7 [[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0
#define UIColorFromRGB(r,g,b) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:1.0f]

#define  DOCUMENTPATH    [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]

//防止循环引用
#define DefineWeakSelf __weak __typeof(self) weakSelf = self

//TabBar NavBar  StatusBar 高度
#define tabHight  44
#define statusHight 20
#define navHight   64

//字符串为nil NuLL
#undef KT_VALUE
#define KT_VALUE(_VAL)  (_VAL)?(_VAL):@""

//大于375宽度屏幕以375为参照按比例取值，其他不变
#define KTSALE_kWidht_NUM  (kWidth / 375.f )
#define KTSALE_kHeight_NUM  (kHeight / 667.f )
#define KTSALE_kWidht_Plus(x)     KTSALE_kWidht_NUM * (x)
#define KTSALE_kHeight_Plus(x)     KTSALE_kHeight_NUM * (x)

#undef	AS_MODEL_STRONG
#define	AS_MODEL_STRONG( __class, __tag ) \
@property (nonatomic, strong) __class *	__tag;

#undef	AS_MODEL_COPY
#define	AS_MODEL_COPY( __class, __tag ) \
@property (nonatomic, copy) __class *	__tag;

#undef	AS_MODEL_ASSIGN
#define	AS_MODEL_ASSIGN( __class, __tag ) \
@property (nonatomic, assign) __class 	__tag;

#undef	AS_MODEL_WEEK
#define	AS_MODEL_WEEK( __class, __tag ) \
@property (nonatomic, week) __class *	__tag;

#undef AS_MODEL_READONLY
#define AS_MODEL_READONLY( __class,  __tag) \
@property (nonatomic,strong,readonly) __class *	__tag;


#undef	AS_MODEL
#define	AS_MODEL( __class, __tag ) \
@property (nonatomic) __class __tag;

#undef	DEF_MODEL
#define	DEF_MODEL( __tag ) \
@synthesize __tag;

#undef	DEF_DYNAMIC
#define	DEF_DYNAMIC( __tag ) \
@dynamic __tag;

#undef  AS_INT_ASSIGN
#define AS_INT_ASSIGN(__tag) \
@property (nonatomic,assign) NSInteger __tag;

#undef  AS_BOOL_ASSIGN
#define AS_BOOL_ASSIGN(__tag) \
@property (nonatomic,assign) BOOL __tag;

#undef  AS_FLOAT_ASSIGN
#define AS_FLOAT_ASSIGN(__tag) \
@property (nonatomic,assign) CGFloat __tag;

#undef  AS_POINT_ASSIGN
#define AS_POINT_ASSIGN(__tag) \
@property (nonatomic,assign) CGPoint __tag;

#undef  AS_SIZE_ASSIGN
#define AS_SIZE_ASSIGN(__tag) \
@property (nonatomic,assign) CGSize __tag;

#undef  AS_RECT_ASSIGN
#define AS_RECT_ASSIGN(__tag) \
@property (nonatomic,assign) CGRect __tag;

#undef  AS_INT
#define AS_INT(__tag) \
AS_MODEL(NSInteger, __tag)

#undef  AS_BOOL
#define AS_BOOL(__tag) \
AS_MODEL(BOOL, __tag)

#undef  AS_FLOAT
#define AS_FLOAT(__tag) \
AS_MODEL(CGFloat, __tag)

#undef  AS_POINT
#define AS_POINT(__tag) \
AS_MODEL(CGPoint, __tag)

#undef  AS_SIZE
#define AS_SIZE(__tag) \
AS_MODEL(CGSize, __tag)

#undef  AS_RECT
#define AS_RECT(__tag) \
AS_MODEL(CGRect, __tag)


CG_INLINE CGRect CGRectMakeKT(CGFloat x,CGFloat y,CGFloat width,CGFloat height)
{
    return CGRectMake(x *KTSALE_kWidht_NUM,  y *KTSALE_kHeight_NUM, width *KTSALE_kWidht_NUM, height *KTSALE_kHeight_NUM);
}

CG_INLINE CGSize CGSizeMakeKT(CGFloat width, CGFloat height)
{
    return CGSizeMake(width *KTSALE_kWidht_NUM, height *KTSALE_kHeight_NUM);
}

CG_INLINE CGPoint CGPointMakeKT(CGFloat x,CGFloat y)
{
    return CGPointMake(x *KTSALE_kWidht_NUM, y *KTSALE_kHeight_NUM);
}

CG_INLINE UIEdgeInsets UIEdgeInsetsMakeKT(CGFloat top,CGFloat  left,CGFloat bottom,CGFloat right)
{
    return UIEdgeInsetsMake( top*KTSALE_kHeight_NUM, left*KTSALE_kHeight_NUM, bottom *KTSALE_kHeight_NUM, right *KTSALE_kHeight_NUM);
}


//外网总地址
#define    TOTALURL   @"http://www.tngou.net/tnfs/api/classify"

//DB数据库地址
#define  DBFILEPATH         @"IntegratedSystem.db"

#endif /* Constants_h */
