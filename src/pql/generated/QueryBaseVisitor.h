
// Generated from ./Query.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "QueryVisitor.h"


namespace pt::PQL {

/**
 * This class provides an empty implementation of QueryVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  QueryBaseVisitor : public QueryVisitor {
public:

  virtual std::any visitFilter(QueryParser::FilterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndExpression(QueryParser::AndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPredicateExpression(QueryParser::PredicateExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrExpression(QueryParser::OrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReference(QueryParser::ReferenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperatorPredicate(QueryParser::OperatorPredicateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOper(QueryParser::OperContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitValue(QueryParser::ValueContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace pt::PQL
