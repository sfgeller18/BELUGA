#include "belugaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
belugaApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

belugaApp::belugaApp(InputParameters parameters) : MooseApp(parameters)
{
  belugaApp::registerAll(_factory, _action_factory, _syntax);
}

belugaApp::~belugaApp() {}

void 
belugaApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<belugaApp>(f, af, s);
  Registry::registerObjectsTo(f, {"belugaApp"});
  Registry::registerActionsTo(af, {"belugaApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
belugaApp::registerApps()
{
  registerApp(belugaApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
belugaApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  belugaApp::registerAll(f, af, s);
}
extern "C" void
belugaApp__registerApps()
{
  belugaApp::registerApps();
}
