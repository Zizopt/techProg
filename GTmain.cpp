#include <gtest/gtest.h>
#include "dopF.h"
#include "mat/multM.h"
#include "mat/multMElem.h"

class TestSerialization : public ::testing::Test {
public:
    double** A = 0, ** B = 0;
    int nA = 0, nB = 0, mA = 0, mB = 0;
    TestSerialization() { 
        /* init protected members here */
        nA = 3;
        mA = 4;
        nB = 4;
        mB = 3;
        A = createM(nA, mA);
        B = createM(nB, mB);
        for (int i = 0; i < nA; i++)
        {
            for (int j = 0; j < mA; j++)
            {
                A[i][j] = j + 1;
                B[j][i] = i + 1;
            }
        }
    }
    ~TestSerialization() { 
        /* free protected members here */ 
        deleteM(A, nA, mA);
        deleteM(B, nB, mB);
    }
    void SetUp() { /* called before every test */ }
    void TearDown() { /* called after every test */ }

protected:
    /* none yet */
};

TEST_F(TestSerialization, MultMElemSizeError) {
    ASSERT_EQ(0, multMElem(A, nA, mA, B, nB, nB));
}
TEST_F(TestSerialization, MultMElemEqel) {
    int n = 3;
    double **C = multMElem(A, n, n, B, n, n);
    double **D = createM(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            D[i][j] = (j + 1) * (j + 1);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            ASSERT_EQ(D[i][j], C[i][j]);
    deleteM(C, n, n);
    deleteM(D, n, n);
}

TEST_F(TestSerialization, MultMSizeError) {
    int n = 3, nC, mC;
    ASSERT_EQ(0, multM(A, nA, mA, B, n, mB, nC, mC));
}

TEST_F(TestSerialization, MultMEqel) {
    int nC, mC;
    double** C = multM(A, nA, mA, B, nB, mB, nC, mC);
    double** D = createM(nA, mB);
    for (int i = 0; i < nC; i++)
        for (int j = 0; j < mC; j++)
            D[i][j] = (j+1)*10;
    for (int i = 0; i < nC; i++)
        for (int j = 0; j < mC; j++)
            ASSERT_EQ(D[i][j], C[i][j]);
    deleteM(C, nC, mC);
    deleteM(D, nC, mC);
}
TEST_F(TestSerialization, TestForTest) {
    ASSERT_EQ(0, 1);   
}

TEST_F(TestSerialization, NoMatrixMultMElem) {
    ASSERT_EQ(0, multMElem(0,0,0,0,0,0));   
}
TEST_F(TestSerialization, NoMatrixMultM) {
	int nC, mC;
    ASSERT_EQ(0, multM(0,0,0,0,0,0,nC,mC));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
