#include <iostream>
#include <enet/enet.h>
#include "napi.h"
#include "HandleFunc.hpp"
#include "Structs/GamePacket.hpp"

// Functions
#include "Functions/Host/Host.hpp"
#include "Functions/Packets/Packets.hpp"

#define VERSION "0.2.0"

using namespace std;
using namespace Napi;

namespace HandleFunc
{
	void reg(Env env, Object exports)
	{
		// General, no categories
		exports.Set(String::New(env, "version"), String::New(env, VERSION));

		// For the Host Property
		Object HostObject = Object::New(env);
		HostObject.Set(String::New(env, "create"), Function::New(env, Host::create));
		HostObject.Set(String::New(env, "start"), Function::New(env, Host::start));
		HostObject.Set(String::New(env, "init"), Function::New(env, Host::init));

		exports.Set(String::New(env, "Host"), HostObject);

		// For the Packets Property
		Object PacketObject = Object::New(env);
		PacketObject.Set(String::New(env, "send"), Function::New(env, Packets::sendRawPacket));
		PacketObject.Set(String::New(env, "quit"), Function::New(env, Packets::sendQuit));
		PacketObject.Set(String::New(env, "sendPacket"), Function::New(env, Packets::sendPacket));

		exports.Set(String::New(env, "Packets"), PacketObject);
	}
}