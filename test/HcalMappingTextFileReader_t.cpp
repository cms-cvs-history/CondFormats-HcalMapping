#include "CondFormats/HcalMapping/interface/HcalMappingTextFileReader.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

  const char* name="test.map";
  if (argc>1) name=argv[1];

  std::auto_ptr<HcalMapping> hrm=HcalMappingTextFileReader::readFromFile(name,true);

  std::vector<HcalDetId>::const_iterator i=hrm->detid_begin();
  for ( ; i!=hrm->detid_end(); i++ ) {
    if (i->rawId()==0) continue;
    cout << *i << " <-> " << hrm->lookup(*i) << endl;
  }

  std::vector<HcalTrigTowerDetId>::const_iterator j=hrm->trigger_detid_begin();
  for ( ; j!=hrm->trigger_detid_end(); j++ ) {
    if (j->rawId()==0) continue;
    cout << *j << " <-> " << hrm->lookupTrigger(*j) << endl;
  }

  return 0;
}
