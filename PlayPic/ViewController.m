//
//  ViewController.m
//  PlayPic
//
//  Created by KT on 2017/7/3.
//  Copyright © 2017年 KEENTEAM. All rights reserved.
//
#import "ViewController.h"

@interface ViewController (){
    
    UIButton *button;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    int y = (arc4random() % 5) + 1;
    self.view.backgroundColor =  [UIColor colorWithPatternImage:[UIImage imageNamed:@"backImge.jpg"]];
    UIImage *image =[UIImage imageNamed:[NSString stringWithFormat:@"%d.jpg",y]];
    CGFloat width =image.size.width/3;
    CGFloat heigh =image.size.height/3;
    
    UIImageView *im =[[UIImageView alloc]initWithImage:image];
    im.frame=CGRectMakeKT(200, 510, 150, 150);
    [self.view addSubview:im];
    
    NSMutableArray *ary =[NSMutableArray array];
    for (int i=0; i<9; i++) {
        int row =i/3;
        int col =i%3;
        UIButton *btn =[UIButton buttonWithType:0];
        btn.frame=CGRectMake(5+col*(100+5), 50+row*105, 100, 100);
        btn.backgroundColor =[UIColor whiteColor];
        [self.view addSubview:btn];

        btn.tag =100+i;
        
        if (i!=2) {
            
            CGRect rec= CGRectMake(col*width, row*heigh, width, heigh);
            //裁剪图片
            CGImageRef imgref = CGImageCreateWithImageInRect(image.CGImage, rec);
            UIImage *little =[UIImage imageWithCGImage:imgref];
            CGImageRelease(imgref);
            
            UIImageView *imageView1 =[[UIImageView alloc]initWithFrame:CGRectMake(50+col*(100+5), 100+row*105, 100, 100)];
            
            
            imageView1.image =little;
            [btn setImage:little forState:UIControlStateNormal];
            
        }
        [ary addObject: [NSValue valueWithCGRect:btn.frame]];
        
        [btn addTarget:self action:@selector(btnClick:) forControlEvents:UIControlEventTouchUpInside];
    }
    
    //产生九个无序的
    NSMutableArray *ary1 =[NSMutableArray array];
    while (1) {
        int random =arc4random()%9;
        
        BOOL iscontaint = NO;
        for (NSNumber *num  in ary1) {
            if ([num intValue]==random) {
                iscontaint =YES;
            }
        }
        if (!iscontaint) {
            [ary1 addObject:[NSNumber numberWithInt:random]];
        }
        if (ary1.count ==9) {
            break;
        }
    }
    
    NSMutableArray *aryframe =[NSMutableArray array];
    for (int i=0; i<9; i++) {
        NSValue *value =ary[[ary1[i] intValue]];
        [aryframe addObject:value];
        
    }
    int index = 0;
    for (UIButton *btn in self.view.subviews) {
        if ([btn isKindOfClass:[UIButton class]]) {
            btn.frame = [aryframe[index] CGRectValue];
            
            index ++;
        }
    }
}

-(void)btnClick:(UIButton *)btn1
{
    UIButton *b =(UIButton *)[self.view viewWithTag:102];
    CGFloat x= b.frame.origin.x;
    CGFloat y =b.frame.origin.y;
    CGFloat x1= btn1.frame.origin.x;
    CGFloat y1 =btn1.frame.origin.y;
    
    if ((x==x1&&fabs(y-y1)==105)||((y==y1&&fabs(x-x1)==105))) {
        CGRect frame = b.frame;
        b.frame = btn1.frame;
        btn1.frame = frame;
        
    }
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
