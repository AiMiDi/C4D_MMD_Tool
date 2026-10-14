import c4d, json, os
from pathlib import Path
ROOT = Path(r'S:\tmp\cmt-update-native-20261014')
class Probe(c4d.plugins.MessageData):
    started = False
    last_sequence = None
    def GetTimer(self): return 500
    def CoreMessage(self, mid, bc):
        if mid != c4d.MSG_TIMER: return True
        if not self.started:
            doc = c4d.documents.GetActiveDocument()
            if doc: doc.SetDocumentName('MMD-Update-Validation.c4d')
            self.preference_command = next((i for i in range(10000, 15000) if c4d.GetCommandName(i) in ('首选项...', '首选项', 'Preferences...', 'Preferences')), None)
            self.started = True
            self.receipt('startup')
        request = ROOT/'request.json'
        if not request.exists(): return True
        try:
            data=json.loads(request.read_text(encoding='utf-8'))
            if data['sequence'] == self.last_sequence: return True
            self.last_sequence=data['sequence']
            action=data['action']
            if action=='use': c4d.CallCommand(1056563)
            elif action=='preferences': c4d.PrefsLib_OpenDialog(1056725)
            elif action=='quit':
                self.receipt(action)
                doc=c4d.documents.GetActiveDocument()
                if doc and doc.GetDocumentName() == 'MMD-Update-Validation.c4d': c4d.documents.KillDocument(doc)
                c4d.CallCommand(12104)
                return True
            elif action!='read': raise ValueError('Unsupported probe action')
            self.receipt(action)
        except Exception as error:
            self.receipt('error:'+str(error))
        return True
    def receipt(self, action):
        p=c4d.plugins.GetWorldPluginData(1056563)
        value={'pid':os.getpid(), 'action':action, 'sequence':self.last_sequence,
            'automatic':p.GetBool(2000000,True) if p else True,
            'ignored':p.GetString(2000001) if p else '',
            'last_attempt':p.GetInt64(2000002) if p else 0,
            'latest':p.GetString(2000003) if p else '',
            'notes_bytes':len(p.GetString(2000004).encode('utf-8')) if p else 0,
            'preferences_plugin':c4d.plugins.FindPlugin(1056725,c4d.PLUGINTYPE_PREFS) is not None,
            'preference_command':self.preference_command,
            'command_names':{str(i):c4d.GetCommandName(i) for i in [12200,12104,1056563]},
            'document':c4d.documents.GetActiveDocument().GetDocumentName()}
        tmp=ROOT/'response.tmp'; tmp.write_text(json.dumps(value,ensure_ascii=False,indent=2),encoding='utf-8'); tmp.replace(ROOT/'response.json')
if __name__=='__main__':
    c4d.plugins.RegisterMessagePlugin(1000001,'Task update probe',0,Probe())
