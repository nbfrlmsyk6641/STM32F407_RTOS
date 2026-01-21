#include <stdio.h>

// * 测试环境用的代码 *//

int main() {
    int sum = 0;
    printf("开始计算...\n");
    
    // 简单的循环测试
    for (int i = 1; i <= 5; i++) {
        sum += i;
        printf("当前 i = %d, sum = %d\n", i, sum);
    }
    
    printf("最终结果: %d\n", sum);
    return 0;
}