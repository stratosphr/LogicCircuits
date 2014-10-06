#include "andGate.h"
#include "CUnit/Basic.h"

void test_AndGate_0_ancestor(void){
    AndGate and1;
    CU_ASSERT_TRUE_FATAL(and1.getAncestors().size() == 0);
    CU_ASSERT_TRUE_FATAL(and1.getOutput() == false);
}

void test_AndGate_1_ancestor(void){
    AndGate and1, and2;
    and2.addSuccessor(&and1);
    CU_ASSERT_TRUE_FATAL(and1.getAncestors().size() == 1);
    CU_ASSERT_TRUE_FATAL(and1.getSuccessors().size() == 0);
    CU_ASSERT_TRUE_FATAL(and2.getAncestors().size() == 0);
    CU_ASSERT_TRUE_FATAL(and2.getSuccessors().size() == 1);
    CU_ASSERT_TRUE_FATAL(and2.getOutput() == false);
    CU_ASSERT_TRUE_FATAL(and1.getOutput() == and2.getOutput());
}

void test_AndGate_2_ancestors(void){
    AndGate and1, and2, and3;
    and2.addSuccessor(&and1);
    and3.addSuccessor(&and1);
    CU_ASSERT_TRUE_FATAL(and1.getAncestors().size() == 2);
    CU_ASSERT_TRUE_FATAL(and1.getSuccessors().size() == 0);
    CU_ASSERT_TRUE_FATAL(and2.getSuccessors().size() == 1);
    CU_ASSERT_TRUE_FATAL(and3.getSuccessors().size() == 1);
    CU_ASSERT_TRUE_FATAL(and2.getAncestors().size() == 0);
    CU_ASSERT_TRUE_FATAL(and3.getAncestors().size() == 0);
    CU_ASSERT_TRUE_FATAL(and2.getOutput() == false);
    CU_ASSERT_TRUE_FATAL(and3.getOutput() == false);
    CU_ASSERT_TRUE_FATAL(and1.getOutput() == (and2.getOutput() && and3.getOutput()));
}

void test_AndGate_10_ancestors(void){
    AndGate and1;
    for(int i=0; i<10; i++){
        AndGate and0;
        and0.addSuccessor(&and1);
        CU_ASSERT_TRUE_FATAL(and0.getAncestors().size() == 0);
        CU_ASSERT_TRUE_FATAL(and0.getSuccessors().size() == 1);
        CU_ASSERT_TRUE_FATAL(and0.getOutput() == false);
    }
    CU_ASSERT_TRUE_FATAL(and1.getAncestors().size() == 10);
    CU_ASSERT_TRUE_FATAL(and1.getSuccessors().size() == 0);
    CU_ASSERT_TRUE_FATAL(and1.getOutput() == false);
}

int main(int argc, char* argv[]){

    if(CUE_SUCCESS != CU_initialize_registry()){
        return CU_get_error();
    }

    CU_pSuite pSuite = CU_add_suite("Test of AndGate", NULL, NULL);
    if(NULL == pSuite){
        CU_cleanup_registry();
        return CU_get_error();
    }

    if(
            (NULL == CU_add_test(pSuite, "AndGate with 0 ancestor", test_AndGate_0_ancestor)) ||
            (NULL == CU_add_test(pSuite, "AndGate with 1 ancestor", test_AndGate_1_ancestor)) ||
            (NULL == CU_add_test(pSuite, "AndGate with 2 ancestors", test_AndGate_2_ancestors)) ||
            (NULL == CU_add_test(pSuite, "AndGate with 10 ancestors", test_AndGate_10_ancestors))
            ){
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();

}
