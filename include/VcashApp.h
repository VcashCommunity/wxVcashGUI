/******************************************************************************
 * wxVcashGUI: a GUI for Vcash, a decentralized currency 
 *             for the internet (https://vcash.info).
 *
 * Copyright (c) The Vcash Developers
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 ******************************************************************************/
 
#ifndef VCASHAPP_H
#define VCASHAPP_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/app.h>
#include <wx/cmdline.h>
#include <wx/ipc.h>
#include <wx/snglinst.h>
#endif

#include "Controller.h"
#include "View.h"

#include <map>
#include <string>

namespace wxGUI {

    class VcashApp : public wxApp {
    public:
        VcashApp();
        void exit();
        bool canExit();

        Controller controller;
        View view;
        bool taskBarIconEnabled;

    private:
        bool OnInit();
        int OnExit();
        void OnInitCmdLine(wxCmdLineParser &parser);
        bool OnCmdLineParsed(wxCmdLineParser &parser);
        void parserURI(std::string uri);

        std::map<std::string, std::string> args;
        static const wxCmdLineEntryDesc cmdLineDesc[];
        wxSingleInstanceChecker singleInstanceChecker;

        // DDE Messages
        class DDEConnection : public wxConnection {
        private:
            VcashApp &vcashApp;
            bool OnExec(const wxString &topic, const wxString &data);
        public:
            DDEConnection(VcashApp &vcashApp);
        };
        class DDEServer : public wxServer {
        private:
            VcashApp &vcashApp;
        public:
            DDEServer(VcashApp &vcashApp);
            DDEConnection *OnAcceptConnection(const wxString &topic);
        };
        DDEServer ddeServer;
    };
}

#endif // VCASHAPP_H