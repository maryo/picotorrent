
// Generated from ./Query.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "QueryParser.h"


namespace pt::PQL {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by QueryParser.
 */
class  QueryVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by QueryParser.
   */
    virtual std::any visitFilter(QueryParser::FilterContext *context) = 0;

    virtual std::any visitAndExpression(QueryParser::AndExpressionContext *context) = 0;

    virtual std::any visitPredicateExpression(QueryParser::PredicateExpressionContext *context) = 0;

    virtual std::any visitOrExpression(QueryParser::OrExpressionContext *context) = 0;

    virtual std::any visitReference(QueryParser::ReferenceContext *context) = 0;

    virtual std::any visitOperatorPredicate(QueryParser::OperatorPredicateContext *context) = 0;

    virtual std::any visitOper(QueryParser::OperContext *context) = 0;

    virtual std::any visitValue(QueryParser::ValueContext *context) = 0;


};

}  // namespace pt::PQL
