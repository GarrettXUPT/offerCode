#include <stdio.h>
#include <time.h>

#include "/usr/local/include/pbc/pbc.h"  //必须包含头文件pbc.h

#define CLOCKS_PER_SEC ((clock_t)1000) 

element_t* generateVec(int n, pairing_t pairing){
    element_t* resVec = (element_t*)malloc(sizeof(element_t) * n);
    for(int i = 0; i < n; ++i){
        element_init_Zr(resVec[i], pairing);
        element_random(resVec[i]);
    }
    return resVec;
}

element_t* vecAdd(element_t* vec1, element_t* vec2, pairing_t pairing, int n){
    element_t* resVec = (element_t*)malloc(sizeof(element_t) * n);
    for(int i = 0; i < n; ++i){
        element_init_Zr(resVec[i], pairing);
        element_add(resVec[i], vec1[i], vec2[i]);
    }
    return resVec;
}

element_t* keyGenPowOp(element_t g, element_t* sVec, pairing_t pairing, int n){
    element_t* resVec =  (element_t*)malloc(sizeof(element_t) * n);
    for(int i = 0; i < n; ++i){
        element_init_G1(resVec[i], pairing);
        element_pow_zn(resVec[i], g, sVec[i]);
    }
    return resVec;
}

element_t* keyGenPairingOp(element_t g, element_t hT, element_t* kVec, pairing_t pairing, int n){
    element_t* resVec =  (element_t*)malloc(sizeof(element_t) * n);
    element_t* tmp = keyGenPowOp(g, kVec, pairing, n);
    for(int i = 0; i < n; ++i){
        element_init_G1(resVec[i], pairing);
        element_pairing(resVec[i], tmp, hT);
    }
    return resVec;
}

element_t** upTriMatrixGen(int k, pairing_t pairing){
    element_t** matrix = (element_t**)malloc(sizeof(element_t*) * k);
    for(int i = k; i > 0; --i){
        matrix[k - i] = (element_t*)malloc(sizeof(element_t) * i);
        for(int j = 0; j < i; j++){
            element_init_Zr(matrix[k - i][j], pairing);
            element_random(matrix[k - i][j]);
        }
    }
    return matrix;
}

element_t** matrixMul(element_t** matrix1, element_t** matrix2, pairing_t pairing, int n){
    element_t** matrix = (element_t**)malloc(sizeof(element_t*) * n);
    for(int i = 0 ; i < n; ++i){
        matrix[i] = (element_t*)malloc(sizeof(element_t) * n);
        for(int j = 0; j < n; ++j){
            element_init_Zr(matrix[i][j], pairing);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; ++j){
            element_t sum;
            element_init_Zr(sum, pairing);
            for(int k = 0; k < n; k++){
                element_t tmp;
                element_init_Zr(tmp, pairing);
                element_mul(tmp, matrix1[i][k], matrix2[k][j]);
                element_add(sum, sum, tmp);
            }
            element_set(matrix[i][j], sum);
        }
    }
    return matrix;
}

element_t* vecMulMat(element_t* vec, element_t** mat, pairing_t pairing, int n){
    element_t* resVec = (element_t*)malloc(sizeof(element_t) * n);
    for(int i = 0 ; i < n; ++i){
        element_t sum;
        element_init_Zr(sum, pairing);
        element_init_Zr(resVec[i], pairing);
        for(int j = 0; j < n; j++){
            element_t tmp;
            element_init_Zr(tmp, pairing);
            element_mul(tmp, vec[j], mat[i][j]);
            element_add(sum, sum, tmp);
        }
        element_set(resVec[i], sum);
    }
    return resVec;
}

element_t** setOneMatrix(int n, pairing_t pairing){
    element_t** matirx = (element_t**)malloc(sizeof(element_t*) * n);
    for(int i = 0; i < n; ++i){
        matirx[i] = (element_t*)malloc(sizeof(element_t) * n);
        for(int j = 0; j <n; ++j){
            element_init_Zr(matirx[i][j], pairing);
            if(i == j){
                element_set1(matirx[i][j]);                
            }else{
                element_set0(matirx[i][j]);
            }
        }
    }
    return matirx;
}

element_t** userMatrixGen(pairing_t pairing, int n){
    element_t** matirx = (element_t**)malloc(sizeof(element_t*) * n);
    for(int i = 0; i < n; ++i){
        matirx[i] = (element_t*)malloc(sizeof(element_t) * n);
        for(int j = 0; j <n; ++j){
            element_init_G1(matirx[i][j], pairing);
            element_set1(matirx[i][j]);
        }
    }
    return matirx;
}

element_t** matrixGenByupTri(pairing_t pairing, element_t** upTriMatirx, int n, int k){
    element_t** matrix = (element_t**)malloc(sizeof(element_t*) * n);
    for(int i = 0; i < n; ++i){
        matrix[i] = (element_t*)malloc(sizeof(element_t) * n);
        for(int m = 0; m < k; ++m){
            element_t* tmp = (element_t*)malloc(sizeof(element_t) * k);
            for(int t = 0; t < k; ++t){
                element_init_G1(tmp[t], pairing);
                // element_invert(tmp[t], upTriMatirx[m][t]);
            }
        }
        for(int j = 0; j < n; ++j){
            element_init_G1(matrix[i][j], pairing);
            element_random(matrix[i][j]);
        }
    }
    return matrix;
}


element_t* mulAndPow(element_t* vec1, element_t* vec2, pairing_t pairing, int n){
    element_t* res = (element_t*)malloc(sizeof(element_t));
    element_init_G1(*res, pairing);
    for(int i = 0; i < n; ++i){
        element_t tmp;
        element_init_G1(tmp, pairing);
        element_pow_zn(tmp, vec1[i], vec2[i]);
        element_mul(*res, *res, tmp);
    }
    return res;
}

element_t*** QRDiv(element_t** matrix, int n, pairing_t pairing){
    element_t*** QR = (element_t***)malloc(sizeof(element_t**) * 2);
    QR[0] = (element_t**)malloc(sizeof(element_t*) * n);
    QR[1] = (element_t**)malloc(sizeof(element_t*) * n);

    for(int i = 0; i < n; ++i){
        QR[0][i] = (element_t*)malloc(sizeof(element_t) * n);
        QR[1][i] = (element_t*)malloc(sizeof(element_t) * n);
        for(int j = 0; j < n; ++j){
            element_init_G1(QR[0][i][j], pairing);
            element_init_G1(QR[1][i][j], pairing);
            element_random(QR[0][i][j]);
            element_invert(QR[1][i][j], QR[0][i][j]);
        }
    }
    return QR;
}


element_t** mVecGen(element_t* pk3Vec, element_t** aTMatrix, pairing_t pairing, int n){
    element_t** mVec = (element_t**)malloc(sizeof(element_t*) * n);
    for(int i = 0; i < n; ++i){
        mVec[i] = (element_t*)malloc(sizeof(element_t) * n);
        mVec[i] =  mulAndPow(pk3Vec, aTMatrix[i], pairing, n);
    }
    return mVec;
}


element_t** matrixTOp(element_t** matrix, pairing_t pairing, int n){
    element_t** matrixT = (element_t**)malloc(sizeof(element_t*) * n);
    for(int i = 0; i < n; ++i){
        matrixT[i] = (element_t*)malloc(sizeof(element_t) * n);
        for(int j = 0; j < n; ++j){
            element_init_Zr(matrixT[i][j], pairing);
            element_set(matrixT[i][j], matrix[j][i]);
        }
    }
    return matrixT;
}


element_t** invertMatrix(element_t**matrix, pairing_t pairing, int n){
    element_t** inMatrix = (element_t**)malloc(sizeof(element_t*) * n);
    for(int i = 0; i < n; ++i){
        inMatrix[i] = (element_t*)malloc(sizeof(element_t) * n);
        for(int j = 0; j < n; ++j){
            element_init_G1(inMatrix[i][j], pairing);
            element_invert(inMatrix[i][j], matrix[i][j]);
        }
    }
    return inMatrix;
}

int matrixCmp(element_t** matrix1, element_t** matrix2, int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n;++j){
            if(!element_cmp(matrix1[i][j], matrix2[i][j])){
                return 1;
            }
        }
    }
    return 0;
}

void freeVec(element_t* vec){
    if(vec != NULL){
        free(vec);
    }
}

void freeMatrix(element_t** matrix, int n){
    if(matrix != NULL){
        for(int i = 0; i < n; ++i){
            freeVec(matrix[i]);
        }
    }
}




int main(int argc, char const *argv[])
{
    // 对pairing进行初始化
    pairing_t pairing; 
    char param[1024];
    size_t count = fread(param, 1, 1024, stdin);//读大小为1的个数最大为1024到param，返回真实读入的个数
    if (!count) pbc_die("input error");
    pairing_init_set_buf(pairing, param, count);

    // 定义变量
    element_t g, h, hT, gT;
    element_t temp1, temp2;
    element_t theta;
    element_init_G1(g, pairing);
    element_init_G1(gT, pairing);
    element_init_Zr(theta, pairing);
    element_init_G2(h, pairing);
    element_init_G2(hT, pairing);
    element_init_GT(temp1, pairing);
    // 随机数随机选取
    element_random(theta);
    // // 数据中心计算
    element_pow_zn(hT, h, theta);
    element_pow_zn(gT, g, theta);
    // // 此处存在公共参数para = (p, G1, G2, GT, g, h, gT, hT)

    int n = 100;
    int k = 10;
    time_t start1, start2, start3, start4, start5;
    time_t end1, end2, end3, end4, end5;
    /*
        秘钥生成
    */
    start1 = clock();
    // 随机产生三个向量
    element_t* sVec = generateVec(n, pairing);
    element_t* lVec = generateVec(n, pairing);
    element_t* kVec = generateVec(n, pairing);

    // // 生成评估秘钥
    element_t* zVec = vecAdd(lVec, kVec, pairing, n);

    // 利用私钥产生公钥
    element_t* pk1Vec = keyGenPowOp(g, sVec, pairing, n);
    element_t* pk2Vec = keyGenPairingOp(g, hT, kVec, pairing, n);
    element_t* pk3Vec = keyGenPowOp(gT, sVec, pairing, n);
    end1 = clock();
    printf("keyGen alg during time = %f\n", ((double)(end1 - start1) / CLOCKS_PER_SEC));
    freeVec(kVec);


    /*
        加密算法
    */
    element_t** pMatrix = setOneMatrix(n, pairing);
    element_t** upTriMatirx = upTriMatrixGen(k, pairing);
    element_t** nMatrix = matrixGenByupTri(pairing, upTriMatirx, n, k);
    start2 = clock();
    element_t** aMatrix = userMatrixGen(pairing, n);
    element_t** tmp = matrixMul(pMatrix, aMatrix, pairing, n);
    element_t** aTMatriix = matrixMul(tmp, nMatrix, pairing, n);

    // 生成辅助向量
    element_t* bVec = vecMulMat(sVec, aTMatriix, pairing, n);
    // 验证钥VK
    element_t* VK = mulAndPow(pk2Vec, bVec, pairing, n);
    end2 = clock();
    printf("ProbGen alg during time = %f\n", ((double)(end2 - start2) / CLOCKS_PER_SEC));
    freeVec(bVec); freeVec(sVec);
    /*
        计算算法
    */
    start3 = clock();
    element_t*** QRT =  QRDiv(aTMatriix, n, pairing);
    element_t** QT = QRT[0]; element_t** RT = QRT[1];
    element_t** mVec = mVecGen(pk3Vec, aTMatriix, pairing, n);
    
    element_t v;
    element_init_G1(v, pairing);
    for(int i = 0; i < n; ++i){
        element_t tmp;
        element_init_G1(tmp, pairing);
        element_pow_zn(tmp, mVec[i][0], zVec[i]);
        element_mul(v, v, tmp);
    }
    end3 = clock();
    printf("Compute alg during time = %f\n", ((double)(end3 - start3) / CLOCKS_PER_SEC));
    freeVec(zVec);  freeVec(pk1Vec); freeVec(pk2Vec); freeVec(pk3Vec);

    /*
        验证算法
    */
    start4 = clock();
    element_t* y1TVec = vecMulMat(lVec, RT, pairing, n);
    element_t* yTVec = vecMulMat(y1TVec, QT, pairing, n);

    element_t** QTT = matrixTOp(QT, pairing, n);
    element_t* y2TVec = vecMulMat(yTVec, QTT, pairing, n);

    if(!element_cmp(y1TVec, y2TVec)){
        printf("QT是一个正交矩阵\n");
    }

    element_t leftTerm;
    element_init_Zr(leftTerm, pairing);
    element_pairing(leftTerm, v, h);

    element_t rightTerm;
    element_init_Zr(rightTerm, pairing);

    element_t* ptmp = mulAndPow(pk1Vec, yTVec, pairing, n);
    element_t pptmp;
    element_init_Zr(pptmp, pairing);
    element_pairing(pptmp, *ptmp, hT);
    element_mul(rightTerm, pptmp, VK);
    if(!element_cmp(rightTerm, leftTerm)){
        printf("结果矩阵 correct\n");
    }
    end4 = clock();
    printf("Verify alg during time = %f\n", ((double)(end4 - start4) / CLOCKS_PER_SEC));
    freeVec(y1TVec); freeVec(y2TVec); freeVec(ptmp);   freeVec(yTVec); freeMatrix(QTT, n);
     freeVec(lVec); freeVec(VK);

    /*
        解密算法
    */
    element_t*** QR = QRDiv(aMatrix, n, pairing);
    element_t** Q = QR[0]; element_t** R = QR[1];
    element_t** inVerN = invertMatrix(nMatrix, pairing, n);
    start5 = clock();
    element_t** pT = matrixTOp(pMatrix, pairing, n);
    element_t** pq = matrixMul(pT, QT, pairing, n);
    element_t** rn = matrixMul(RT, inVerN, pairing, n);
    end5 = clock();
    element_t** finalA = matrixMul(pq, rn, pairing, n);

    if(!matrixCmp(finalA, aMatrix, n)){
        printf("加解密 correct\n");
    }
    printf("Solve alg during time = %f\n", ((double)(end5 - start5) / CLOCKS_PER_SEC));


    freeMatrix(pMatrix, n); freeMatrix(aMatrix, n);  freeMatrix(nMatrix, n);
    freeMatrix(tmp, n); freeMatrix(aTMatriix, n);
    freeMatrix(QT, n); freeMatrix(RT, n); 
    freeMatrix(Q, n); freeMatrix(R, n); freeMatrix(pT, n); freeMatrix(inVerN, n);
    freeMatrix(pq, n); freeMatrix(rn, n); freeMatrix(finalA, n);


    return 0;
}
