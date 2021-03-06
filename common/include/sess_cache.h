#ifndef __SESS_CACHE_H__
#define __SESS_CACHE_H__

#include <string>
#include <vector>
#include "session.pb.h"
#include "json/json.h"
#include "base/ef_btype.h"

namespace gim{

using namespace std;
using namespace ef;


class SessCache{
public:
	virtual ~SessCache(){}
	virtual int getSession(const string &key, vector<Sess> &m) = 0;
	virtual int setSession(const Sess &s) = 0;
	virtual int delSession(const Sess &s) = 0;
};

class SsChFactory{
public:
	virtual ~SsChFactory(){};
	virtual SessCache* newSessCache() = 0;
	static int init(const Json::Value& conf);
	static void free();
	static SsChFactory* get();
	static SsChFactory* create(const Json::Value& conf);
private:
	static SsChFactory* g_fct;
};


}

#endif
