/*-----------------------------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2014-2015 Kim Kulling

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
-----------------------------------------------------------------------------------------------*/
#include "gtest/gtest.h"

#include <openddlparser/OpenDDLCommon.h>
#include <openddlparser/OpenDDLParser.h>
#include "UnitTestCommon.h"

BEGIN_ODDLPARSER_NS

class OpenDDLDefectsTest : public testing::Test {
};

TEST_F( OpenDDLDefectsTest, Issue20_WrongColorNodeParsing ) {
    char token[] = "{0.588235, 0.588235, 0.588235}\n";
    size_t len( 0 );
    char *end = findEnd( token, len );

    Value *data( nullptr );
    Reference *refs( ddl_nullptr );
    size_t numRefs( 0 ), numValues( 0 );
    char *in = OpenDDLParser::parseDataList( token, end, &data, numValues, &refs, numRefs );
    ASSERT_NE( nullptr, in );
    ASSERT_NE( nullptr, data );
    ASSERT_EQ( 3, numValues );
}

END_ODDLPARSER_NS