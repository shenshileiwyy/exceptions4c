
# include "testing.h"


DEFINE_TEST(
	b01,
	"try{...} after having ended",
	"This test uses the library in an inconsistent way, by attempting to <strong>start a <code>try</code> block</strong>, after having called <code>e4c_context_end()</code>. The library must signal the misuse by throwing the exception <code>ContextHasNotBegunYet</code>.",
	EXIT_FAILURE,
	"before_TRY_block",
	"ContextHasNotBegunYet"
){

	printf("before_CONTEXT_BEGIN\n");

	e4c_context_begin(e4c_true, e4c_print_exception);

	printf("before_CONTEXT_END\n");

	e4c_context_end();

	printf("before_TRY_block\n");

	E4C_TRY{

		printf("inside_TRY_block\n");

	}

	printf("after_TRY_block\n");

	return(EXIT_SUCCESS);
}