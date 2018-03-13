#include <QString>
#include <QtTest>

class SudokuTestsTest : public QObject
{
    Q_OBJECT

public:
    SudokuTestsTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
};

SudokuTestsTest::SudokuTestsTest()
{
}

void SudokuTestsTest::initTestCase()
{
}

void SudokuTestsTest::cleanupTestCase()
{
}

void SudokuTestsTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(SudokuTestsTest)

#include "tst_sudokuteststest.moc"
