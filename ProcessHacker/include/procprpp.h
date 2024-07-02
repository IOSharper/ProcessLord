#ifndef PH_PROCPRPP_H
#define PH_PROCPRPP_H

#include <thrdlist.h>
#include <modlist.h>
#include <hndllist.h>
#include <memlist.h>
#include <memprv.h>

typedef struct _PH_PROCESS_PROPSHEETCONTEXT
{
    WNDPROC OldWndProc;
    PH_LAYOUT_MANAGER LayoutManager;
    PPH_LAYOUT_ITEM TabPageItem;
    BOOLEAN LayoutInitialized;
} PH_PROCESS_PROPSHEETCONTEXT, *PPH_PROCESS_PROPSHEETCONTEXT;

VOID NTAPI PhpProcessPropContextDeleteProcedure(
    _In_ PVOID Object,
    _In_ ULONG Flags
    );

INT CALLBACK PhpPropSheetProc(
    _In_ HWND hwndDlg,
    _In_ UINT uMsg,
    _In_ LPARAM lParam
    );

PPH_PROCESS_PROPSHEETCONTEXT PhpGetPropSheetContext(
    _In_ HWND hwnd
    );

LRESULT CALLBACK PhpPropSheetWndProc(
    _In_ HWND hwnd,
    _In_ UINT uMsg,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
    );

VOID NTAPI PhpProcessPropPageContextDeleteProcedure(
    _In_ PVOID Object,
    _In_ ULONG Flags
    );

INT CALLBACK PhpStandardPropPageProc(
    _In_ HWND hwnd,
    _In_ UINT uMsg,
    _In_ LPPROPSHEETPAGE ppsp
    );

INT_PTR CALLBACK PhpProcessGeneralDlgProc(
    _In_ HWND hwndDlg,
    _In_ UINT uMsg,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
    );

INT_PTR CALLBACK PhpProcessStatisticsDlgProc(
    _In_ HWND hwndDlg,
    _In_ UINT uMsg,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
    );

INT_PTR CALLBACK PhpProcessPerformanceDlgProc(
    _In_ HWND hwndDlg,
    _In_ UINT uMsg,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
    );

INT_PTR CALLBACK PhpProcessThreadsDlgProc(
    _In_ HWND hwndDlg,
    _In_ UINT uMsg,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
    );

INT_PTR CALLBACK PhpProcessTokenHookProc(
    _In_ HWND hwndDlg,
    _In_ UINT uMsg,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
    );

INT_PTR CALLBACK PhpProcessModulesDlgProc(
    _In_ HWND hwndDlg,
    _In_ UINT uMsg,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
    );

INT_PTR CALLBACK PhpProcessMemoryDlgProc(
    _In_ HWND hwndDlg,
    _In_ UINT uMsg,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
    );

INT_PTR CALLBACK PhpProcessEnvironmentDlgProc(
    _In_ HWND hwndDlg,
    _In_ UINT uMsg,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
    );

INT_PTR CALLBACK PhpProcessHandlesDlgProc(
    _In_ HWND hwndDlg,
    _In_ UINT uMsg,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
    );

INT_PTR CALLBACK PhpProcessServicesDlgProc(
    _In_ HWND hwndDlg,
    _In_ UINT uMsg,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
    );

#define WM_PH_THREADS_UPDATED (WM_APP + 200)
#define WM_PH_THREAD_SELECTION_CHANGED (WM_APP + 201)

// begin_phapppub
typedef struct _PH_THREADS_CONTEXT
{
    PPH_THREAD_PROVIDER Provider;
    PH_CALLBACK_REGISTRATION ProviderRegistration;
    PH_CALLBACK_REGISTRATION AddedEventRegistration;
    PH_CALLBACK_REGISTRATION ModifiedEventRegistration;
    PH_CALLBACK_REGISTRATION RemovedEventRegistration;
    PH_CALLBACK_REGISTRATION UpdatedEventRegistration;
    PH_CALLBACK_REGISTRATION LoadingStateChangedEventRegistration;

    HWND WindowHandle;
// end_phapppub

    union
    {
        PH_THREAD_LIST_CONTEXT ListContext;
        struct
        {
            HWND Private; // phapppub
            HWND TreeNewHandle; // phapppub
        } PublicUse;
    };
    PH_PROVIDER_EVENT_QUEUE EventQueue;
// begin_phapppub
} PH_THREADS_CONTEXT, *PPH_THREADS_CONTEXT;
// end_phapppub

#define WM_PH_MODULES_UPDATED (WM_APP + 210)

// begin_phapppub
typedef struct _PH_MODULES_CONTEXT
{
    PPH_MODULE_PROVIDER Provider;
    PH_PROVIDER_REGISTRATION ProviderRegistration;
    PH_CALLBACK_REGISTRATION AddedEventRegistration;
    PH_CALLBACK_REGISTRATION ModifiedEventRegistration;
    PH_CALLBACK_REGISTRATION RemovedEventRegistration;
    PH_CALLBACK_REGISTRATION UpdatedEventRegistration;

    HWND WindowHandle;
// end_phapppub

    union
    {
        PH_MODULE_LIST_CONTEXT ListContext;
        struct
        {
            HWND Private; // phapppub
            HWND TreeNewHandle; // phapppub
        } PublicUse;
    };
    PH_PROVIDER_EVENT_QUEUE EventQueue;
    NTSTATUS LastRunStatus;
    PPH_STRING ErrorMessage;
// begin_phapppub
} PH_MODULES_CONTEXT, *PPH_MODULES_CONTEXT;
// end_phapppub

#define WM_PH_HANDLES_UPDATED (WM_APP + 220)

// begin_phapppub
typedef struct _PH_HANDLES_CONTEXT
{
    PPH_HANDLE_PROVIDER Provider;
    PH_PROVIDER_REGISTRATION ProviderRegistration;
    PH_CALLBACK_REGISTRATION AddedEventRegistration;
    PH_CALLBACK_REGISTRATION ModifiedEventRegistration;
    PH_CALLBACK_REGISTRATION RemovedEventRegistration;
    PH_CALLBACK_REGISTRATION UpdatedEventRegistration;

    HWND WindowHandle;
// end_phapppub

    union
    {
        PH_HANDLE_LIST_CONTEXT ListContext;
        struct
        {
            HWND Private; // phapppub
            HWND TreeNewHandle; // phapppub
        } PublicUse;
    };
    PH_PROVIDER_EVENT_QUEUE EventQueue;
    BOOLEAN SelectedHandleProtected;
    BOOLEAN SelectedHandleInherit;
    NTSTATUS LastRunStatus;
    PPH_STRING ErrorMessage;
// begin_phapppub
} PH_HANDLES_CONTEXT, *PPH_HANDLES_CONTEXT;
// end_phapppub

// begin_phapppub
typedef struct _PH_MEMORY_CONTEXT
{
    HANDLE ProcessId;
    HWND WindowHandle;
// end_phapppub

    union
    {
        PH_MEMORY_LIST_CONTEXT ListContext;
        struct
        {
            HWND Private; // phapppub
            HWND TreeNewHandle; // phapppub
        } PublicUse;
    };
    PH_MEMORY_ITEM_LIST MemoryItemList;
    BOOLEAN MemoryItemListValid;
    NTSTATUS LastRunStatus;
    PPH_STRING ErrorMessage;
// begin_phapppub
} PH_MEMORY_CONTEXT, *PPH_MEMORY_CONTEXT;
// end_phapppub

#define WM_PH_STATISTICS_UPDATE (WM_APP + 231)

typedef struct _PH_STATISTICS_CONTEXT
{
    PH_CALLBACK_REGISTRATION ProcessesUpdatedRegistration;

    HWND WindowHandle;
    BOOLEAN Enabled;
    HANDLE ProcessHandle;
} PH_STATISTICS_CONTEXT, *PPH_STATISTICS_CONTEXT;

#define WM_PH_PERFORMANCE_UPDATE (WM_APP + 241)

typedef struct _PH_PERFORMANCE_CONTEXT
{
    PH_CALLBACK_REGISTRATION ProcessesUpdatedRegistration;

    HWND WindowHandle;

    PH_GRAPH_STATE CpuGraphState;
    PH_GRAPH_STATE PrivateGraphState;
    PH_GRAPH_STATE IoGraphState;

    HWND CpuGraphHandle;
    HWND PrivateGraphHandle;
    HWND IoGraphHandle;
} PH_PERFORMANCE_CONTEXT, *PPH_PERFORMANCE_CONTEXT;

typedef struct _PH_ENVIRONMENT_CONTEXT
{
    HWND ListViewHandle;
    PPH_LIST Values;
} PH_ENVIRONMENT_CONTEXT, *PPH_ENVIRONMENT_CONTEXT;

#endif
