#ifndef _JAVA_JVMTI_H_
#define _JAVA_JVMTI_H_

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif



struct _jvmtiEnv;

struct jvmtiInterface_1_;

#ifdef __cplusplus
typedef _jvmtiEnv jvmtiEnv;
#else
typedef const struct jvmtiInterface_1_ *jvmtiEnv;
#endif /* __cplusplus */

/* Derived Base Types */

typedef jobject jthread;
typedef jobject jthreadGroup;
typedef jlong jlocation;

enum {
    JVMTI_VISIT_OBJECTS = 0x100,
    JVMTI_VISIT_ABORT = 0x8000
};

    /* Heap Reference Enumeration */

typedef enum {
    JVMTI_HEAP_REFERENCE_CLASS = 1,
    JVMTI_HEAP_REFERENCE_FIELD = 2,
    JVMTI_HEAP_REFERENCE_ARRAY_ELEMENT = 3,
    JVMTI_HEAP_REFERENCE_CLASS_LOADER = 4,
    JVMTI_HEAP_REFERENCE_SIGNERS = 5,
    JVMTI_HEAP_REFERENCE_PROTECTION_DOMAIN = 6,
    JVMTI_HEAP_REFERENCE_INTERFACE = 7,
    JVMTI_HEAP_REFERENCE_STATIC_FIELD = 8,
    JVMTI_HEAP_REFERENCE_CONSTANT_POOL = 9,
    JVMTI_HEAP_REFERENCE_SUPERCLASS = 10,
    JVMTI_HEAP_REFERENCE_JNI_GLOBAL = 21,
    JVMTI_HEAP_REFERENCE_SYSTEM_CLASS = 22,
    JVMTI_HEAP_REFERENCE_MONITOR = 23,
    JVMTI_HEAP_REFERENCE_STACK_LOCAL = 24,
    JVMTI_HEAP_REFERENCE_JNI_LOCAL = 25,
    JVMTI_HEAP_REFERENCE_THREAD = 26,
    JVMTI_HEAP_REFERENCE_OTHER = 27
} jvmtiHeapReferenceKind;

    /* Primitive Type Enumeration */

typedef enum {
    JVMTI_PRIMITIVE_TYPE_BOOLEAN = 90,
    JVMTI_PRIMITIVE_TYPE_BYTE = 66,
    JVMTI_PRIMITIVE_TYPE_CHAR = 67,
    JVMTI_PRIMITIVE_TYPE_SHORT = 83,
    JVMTI_PRIMITIVE_TYPE_INT = 73,
    JVMTI_PRIMITIVE_TYPE_LONG = 74,
    JVMTI_PRIMITIVE_TYPE_FLOAT = 70,
    JVMTI_PRIMITIVE_TYPE_DOUBLE = 68
} jvmtiPrimitiveType;

    /* Heap Root Kind Enumeration */

typedef enum {
    JVMTI_HEAP_ROOT_JNI_GLOBAL = 1,
    JVMTI_HEAP_ROOT_SYSTEM_CLASS = 2,
    JVMTI_HEAP_ROOT_MONITOR = 3,
    JVMTI_HEAP_ROOT_STACK_LOCAL = 4,
    JVMTI_HEAP_ROOT_JNI_LOCAL = 5,
    JVMTI_HEAP_ROOT_THREAD = 6,
    JVMTI_HEAP_ROOT_OTHER = 7
} jvmtiHeapRootKind;

    /* Object Reference Enumeration */

typedef enum {
    JVMTI_REFERENCE_CLASS = 1,
    JVMTI_REFERENCE_FIELD = 2,
    JVMTI_REFERENCE_ARRAY_ELEMENT = 3,
    JVMTI_REFERENCE_CLASS_LOADER = 4,
    JVMTI_REFERENCE_SIGNERS = 5,
    JVMTI_REFERENCE_PROTECTION_DOMAIN = 6,
    JVMTI_REFERENCE_INTERFACE = 7,
    JVMTI_REFERENCE_STATIC_FIELD = 8,
    JVMTI_REFERENCE_CONSTANT_POOL = 9
} jvmtiObjectReferenceKind;

    /* Iteration Control Enumeration */

typedef enum {
    JVMTI_ITERATION_CONTINUE = 1,
    JVMTI_ITERATION_IGNORE = 2,
    JVMTI_ITERATION_ABORT = 0
} jvmtiIterationControl;

    /* Extension Function/Event Parameter Types */

typedef enum {
    JVMTI_TYPE_JBYTE = 101,
    JVMTI_TYPE_JCHAR = 102,
    JVMTI_TYPE_JSHORT = 103,
    JVMTI_TYPE_JINT = 104,
    JVMTI_TYPE_JLONG = 105,
    JVMTI_TYPE_JFLOAT = 106,
    JVMTI_TYPE_JDOUBLE = 107,
    JVMTI_TYPE_JBOOLEAN = 108,
    JVMTI_TYPE_JOBJECT = 109,
    JVMTI_TYPE_JTHREAD = 110,
    JVMTI_TYPE_JCLASS = 111,
    JVMTI_TYPE_JVALUE = 112,
    JVMTI_TYPE_JFIELDID = 113,
    JVMTI_TYPE_JMETHODID = 114,
    JVMTI_TYPE_CCHAR = 115,
    JVMTI_TYPE_CVOID = 116,
    JVMTI_TYPE_JNIENV = 117
} jvmtiParamTypes;

    /* Extension Function/Event Parameter Kinds */

typedef enum {
    JVMTI_KIND_IN = 91,
    JVMTI_KIND_IN_PTR = 92,
    JVMTI_KIND_IN_BUF = 93,
    JVMTI_KIND_ALLOC_BUF = 94,
    JVMTI_KIND_ALLOC_ALLOC_BUF = 95,
    JVMTI_KIND_OUT = 96,
    JVMTI_KIND_OUT_BUF = 97
} jvmtiParamKind;

    /* Timer Kinds */

typedef enum {
    JVMTI_TIMER_USER_CPU = 30,
    JVMTI_TIMER_TOTAL_CPU = 31,
    JVMTI_TIMER_ELAPSED = 32
} jvmtiTimerKind;

typedef enum {
    JVMTI_ERROR_NONE = 0,
    
    JVMTI_ERROR_ACCESS_DENIED = 111,
    
} jvmtiError;

    /* Event IDs */

typedef enum {
    JVMTI_MIN_EVENT_TYPE_VAL = 50,
    JVMTI_EVENT_VM_INIT = 50,
    JVMTI_EVENT_VM_DEATH = 51,
    JVMTI_EVENT_THREAD_START = 52,
    JVMTI_EVENT_THREAD_END = 53,
    JVMTI_EVENT_CLASS_FILE_LOAD_HOOK = 54,
    JVMTI_EVENT_CLASS_LOAD = 55,
    JVMTI_EVENT_CLASS_PREPARE = 56,
    JVMTI_EVENT_VM_START = 57,
    JVMTI_EVENT_EXCEPTION = 58,
    JVMTI_EVENT_EXCEPTION_CATCH = 59,
    JVMTI_EVENT_SINGLE_STEP = 60,
    JVMTI_EVENT_FRAME_POP = 61,
    JVMTI_EVENT_BREAKPOINT = 62,
    JVMTI_EVENT_FIELD_ACCESS = 63,
    JVMTI_EVENT_FIELD_MODIFICATION = 64,
    JVMTI_EVENT_METHOD_ENTRY = 65,
    JVMTI_EVENT_METHOD_EXIT = 66,
    JVMTI_EVENT_NATIVE_METHOD_BIND = 67,
    JVMTI_EVENT_COMPILED_METHOD_LOAD = 68,
    JVMTI_EVENT_COMPILED_METHOD_UNLOAD = 69,
    JVMTI_EVENT_DYNAMIC_CODE_GENERATED = 70,
    JVMTI_EVENT_DATA_DUMP_REQUEST = 71,
    JVMTI_EVENT_MONITOR_WAIT = 73,
    JVMTI_EVENT_MONITOR_WAITED = 74,
    JVMTI_EVENT_MONITOR_CONTENDED_ENTER = 75,
    JVMTI_EVENT_MONITOR_CONTENDED_ENTERED = 76,
    JVMTI_EVENT_RESOURCE_EXHAUSTED = 80,
    JVMTI_EVENT_GARBAGE_COLLECTION_START = 81,
    JVMTI_EVENT_GARBAGE_COLLECTION_FINISH = 82,
    JVMTI_EVENT_OBJECT_FREE = 83,
    JVMTI_EVENT_VM_OBJECT_ALLOC = 84,
    JVMTI_MAX_EVENT_TYPE_VAL = 84
} jvmtiEvent;


    /* Pre-Declarations */
struct _jvmtiThreadInfo;
typedef struct _jvmtiThreadInfo jvmtiThreadInfo;
struct _jvmtiMonitorStackDepthInfo;
typedef struct _jvmtiMonitorStackDepthInfo jvmtiMonitorStackDepthInfo;
struct _jvmtiThreadGroupInfo;
typedef struct _jvmtiThreadGroupInfo jvmtiThreadGroupInfo;
struct _jvmtiFrameInfo;
typedef struct _jvmtiFrameInfo jvmtiFrameInfo;
struct _jvmtiStackInfo;
typedef struct _jvmtiStackInfo jvmtiStackInfo;
struct _jvmtiHeapReferenceInfoField;
typedef struct _jvmtiHeapReferenceInfoField jvmtiHeapReferenceInfoField;
struct _jvmtiHeapReferenceInfoArray;
typedef struct _jvmtiHeapReferenceInfoArray jvmtiHeapReferenceInfoArray;
struct _jvmtiHeapReferenceInfoConstantPool;
typedef struct _jvmtiHeapReferenceInfoConstantPool jvmtiHeapReferenceInfoConstantPool;
struct _jvmtiHeapReferenceInfoStackLocal;
typedef struct _jvmtiHeapReferenceInfoStackLocal jvmtiHeapReferenceInfoStackLocal;
struct _jvmtiHeapReferenceInfoJniLocal;
typedef struct _jvmtiHeapReferenceInfoJniLocal jvmtiHeapReferenceInfoJniLocal;
struct _jvmtiHeapReferenceInfoReserved;
typedef struct _jvmtiHeapReferenceInfoReserved jvmtiHeapReferenceInfoReserved;
union _jvmtiHeapReferenceInfo;
typedef union _jvmtiHeapReferenceInfo jvmtiHeapReferenceInfo;
struct _jvmtiHeapCallbacks;
typedef struct _jvmtiHeapCallbacks jvmtiHeapCallbacks;
struct _jvmtiClassDefinition;
typedef struct _jvmtiClassDefinition jvmtiClassDefinition;
struct _jvmtiMonitorUsage;
typedef struct _jvmtiMonitorUsage jvmtiMonitorUsage;
struct _jvmtiLineNumberEntry;
typedef struct _jvmtiLineNumberEntry jvmtiLineNumberEntry;
struct _jvmtiLocalVariableEntry;
typedef struct _jvmtiLocalVariableEntry jvmtiLocalVariableEntry;
struct _jvmtiParamInfo;
typedef struct _jvmtiParamInfo jvmtiParamInfo;
struct _jvmtiExtensionFunctionInfo;
typedef struct _jvmtiExtensionFunctionInfo jvmtiExtensionFunctionInfo;
struct _jvmtiExtensionEventInfo;
typedef struct _jvmtiExtensionEventInfo jvmtiExtensionEventInfo;
struct _jvmtiTimerInfo;
typedef struct _jvmtiTimerInfo jvmtiTimerInfo;
struct _jvmtiAddrLocationMap;
typedef struct _jvmtiAddrLocationMap jvmtiAddrLocationMap;

    /* Function Types */

typedef void (JNICALL *jvmtiStartFunction)
    (jvmtiEnv* jvmti_env, JNIEnv* jni_env, void* arg);

typedef jint (JNICALL *jvmtiHeapIterationCallback)
    (jlong class_tag, jlong size, jlong* tag_ptr, jint length, void* user_data);

typedef jint (JNICALL *jvmtiHeapReferenceCallback)
    (jvmtiHeapReferenceKind reference_kind, const jvmtiHeapReferenceInfo* reference_info, jlong class_tag, jlong referrer_class_tag, jlong size, jlong* tag_ptr, jlong* referrer_tag_ptr, jint length, void* user_data);

typedef jint (JNICALL *jvmtiPrimitiveFieldCallback)
    (jvmtiHeapReferenceKind kind, const jvmtiHeapReferenceInfo* info, jlong object_class_tag, jlong* object_tag_ptr, jvalue value, jvmtiPrimitiveType value_type, void* user_data);

typedef jint (JNICALL *jvmtiArrayPrimitiveValueCallback)
    (jlong class_tag, jlong size, jlong* tag_ptr, jint element_count, jvmtiPrimitiveType element_type, const void* elements, void* user_data);

typedef jint (JNICALL *jvmtiStringPrimitiveValueCallback)
    (jlong class_tag, jlong size, jlong* tag_ptr, const jchar* value, jint value_length, void* user_data);

typedef jint (JNICALL *jvmtiReservedCallback)
    ();

typedef jvmtiIterationControl (JNICALL *jvmtiHeapObjectCallback)
    (jlong class_tag, jlong size, jlong* tag_ptr, void* user_data);

typedef jvmtiIterationControl (JNICALL *jvmtiHeapRootCallback)
    (jvmtiHeapRootKind root_kind, jlong class_tag, jlong size, jlong* tag_ptr, void* user_data);

typedef jvmtiIterationControl (JNICALL *jvmtiStackReferenceCallback)
    (jvmtiHeapRootKind root_kind, jlong class_tag, jlong size, jlong* tag_ptr, jlong thread_tag, jint depth, jmethodID method, jint slot, void* user_data);

typedef jvmtiIterationControl (JNICALL *jvmtiObjectReferenceCallback)
    (jvmtiObjectReferenceKind reference_kind, jlong class_tag, jlong size, jlong* tag_ptr, jlong referrer_tag, jint referrer_index, void* user_data);

typedef jvmtiError (JNICALL *jvmtiExtensionFunction)
    (jvmtiEnv* jvmti_env,  ...);

typedef void (JNICALL *jvmtiExtensionEvent)
    (jvmtiEnv* jvmti_env,  ...);


    /* Structure Types */
struct _jvmtiThreadInfo {
    char* name;
    jint priority;
    jboolean is_daemon;
    jthreadGroup thread_group;
    jobject context_class_loader;
};
struct _jvmtiMonitorStackDepthInfo {
    jobject monitor;
    jint stack_depth;
};
struct _jvmtiThreadGroupInfo {
    jthreadGroup parent;
    char* name;
    jint max_priority;
    jboolean is_daemon;
};
struct _jvmtiFrameInfo {
    jmethodID method;
    jlocation location;
};
struct _jvmtiStackInfo {
    jthread thread;
    jint state;
    jvmtiFrameInfo* frame_buffer;
    jint frame_count;
};
struct _jvmtiHeapReferenceInfoField {
    jint index;
};
struct _jvmtiHeapReferenceInfoArray {
    jint index;
};
struct _jvmtiHeapReferenceInfoConstantPool {
    jint index;
};
struct _jvmtiHeapReferenceInfoStackLocal {
    jlong thread_tag;
    jlong thread_id;
    jint depth;
    jmethodID method;
    jlocation location;
    jint slot;
};
struct _jvmtiHeapReferenceInfoJniLocal {
    jlong thread_tag;
    jlong thread_id;
    jint depth;
    jmethodID method;
};
struct _jvmtiHeapReferenceInfoReserved {
    jlong reserved1;
    jlong reserved2;
    jlong reserved3;
    jlong reserved4;
    jlong reserved5;
    jlong reserved6;
    jlong reserved7;
    jlong reserved8;
};
union _jvmtiHeapReferenceInfo {
    jvmtiHeapReferenceInfoField field;
    jvmtiHeapReferenceInfoArray array;
    jvmtiHeapReferenceInfoConstantPool constant_pool;
    jvmtiHeapReferenceInfoStackLocal stack_local;
    jvmtiHeapReferenceInfoJniLocal jni_local;
    jvmtiHeapReferenceInfoReserved other;
};
struct _jvmtiHeapCallbacks {
    jvmtiHeapIterationCallback heap_iteration_callback;
    jvmtiHeapReferenceCallback heap_reference_callback;
    jvmtiPrimitiveFieldCallback primitive_field_callback;
    jvmtiArrayPrimitiveValueCallback array_primitive_value_callback;
    jvmtiStringPrimitiveValueCallback string_primitive_value_callback;
    jvmtiReservedCallback reserved5;
    jvmtiReservedCallback reserved6;
    jvmtiReservedCallback reserved7;
    jvmtiReservedCallback reserved8;
    jvmtiReservedCallback reserved9;
    jvmtiReservedCallback reserved10;
    jvmtiReservedCallback reserved11;
    jvmtiReservedCallback reserved12;
    jvmtiReservedCallback reserved13;
    jvmtiReservedCallback reserved14;
    jvmtiReservedCallback reserved15;
};
struct _jvmtiClassDefinition {
    jclass klass;
    jint class_byte_count;
    const unsigned char* class_bytes;
};
struct _jvmtiMonitorUsage {
    jthread owner;
    jint entry_count;
    jint waiter_count;
    jthread* waiters;
    jint notify_waiter_count;
    jthread* notify_waiters;
};
struct _jvmtiLineNumberEntry {
    jlocation start_location;
    jint line_number;
};
struct _jvmtiLocalVariableEntry {
    jlocation start_location;
    jint length;
    char* name;
    char* signature;
    char* generic_signature;
    jint slot;
};
struct _jvmtiParamInfo {
    char* name;
    jvmtiParamKind kind;
    jvmtiParamTypes base_type;
    jboolean null_ok;
};
struct _jvmtiExtensionFunctionInfo {
    jvmtiExtensionFunction func;
    char* id;
    char* short_description;
    jint param_count;
    jvmtiParamInfo* params;
    jint error_count;
    jvmtiError* errors;
};
struct _jvmtiExtensionEventInfo {
    jint extension_event_index;
    char* id;
    char* short_description;
    jint param_count;
    jvmtiParamInfo* params;
};
struct _jvmtiTimerInfo {
    jlong max_value;
    jboolean may_skip_forward;
    jboolean may_skip_backward;
    jvmtiTimerKind kind;
    jlong reserved1;
    jlong reserved2;
};
struct _jvmtiAddrLocationMap {
    const void* start_address;
    jlocation location;
};

typedef struct {
    unsigned int can_tag_objects : 1;
    
    unsigned int can_generate_garbage_collection_events : 1;
    
} jvmtiCapabilities;



    /* Event Callback Structure */




    /* Function Interface */

typedef struct jvmtiInterface_1_ {

  

  /*   47 : Deallocate */
  jvmtiError (JNICALL *Deallocate) (jvmtiEnv* env,
    unsigned char* mem);

  /*   48 : Get Class Signature */
  jvmtiError (JNICALL *GetClassSignature) (jvmtiEnv* env,
    jclass klass,
    char** signature_ptr,
    char** generic_ptr);

  

  /*   78 : Get Loaded Classes */
  jvmtiError (JNICALL *GetLoadedClasses) (jvmtiEnv* env,
    jint* class_count_ptr,
    jclass** classes_ptr);

  

  /*   89 : Get Capabilities */
  jvmtiError (JNICALL *GetCapabilities) (jvmtiEnv* env,
    jvmtiCapabilities* capabilities_ptr);

  

  /*   107 : Set Tag */
  jvmtiError (JNICALL *SetTag) (jvmtiEnv* env,
    jobject object,
    jlong tag);

  

  /*   115 : Follow References */
  jvmtiError (JNICALL *FollowReferences) (jvmtiEnv* env,
    jint heap_filter,
    jclass klass,
    jobject initial_object,
    const jvmtiHeapCallbacks* callbacks,
    const void* user_data);

  

  /*   142 : Add Capabilities */
  jvmtiError (JNICALL *AddCapabilities) (jvmtiEnv* env,
    const jvmtiCapabilities* capabilities_ptr);

  

} jvmtiInterface_1;

struct _jvmtiEnv {
    const struct jvmtiInterface_1_ *functions;
#ifdef __cplusplus


  jvmtiError Deallocate(unsigned char* mem) {
    return functions->Deallocate(this, mem);
  }

  

  jvmtiError FollowReferences(jint heap_filter,
            jclass klass,
            jobject initial_object,
            const jvmtiHeapCallbacks* callbacks,
            const void* user_data) {
    return functions->FollowReferences(this, heap_filter, klass, initial_object, callbacks, user_data);
  }


  jvmtiError SetTag(jobject object,
            jlong tag) {
    return functions->SetTag(this, object, tag);
  }



  jvmtiError GetLoadedClasses(jint* class_count_ptr,
            jclass** classes_ptr) {
    return functions->GetLoadedClasses(this, class_count_ptr, classes_ptr);
  }

  jvmtiError GetClassSignature(jclass klass,
            char** signature_ptr,
            char** generic_ptr) {
    return functions->GetClassSignature(this, klass, signature_ptr, generic_ptr);
  }

  

  jvmtiError AddCapabilities(const jvmtiCapabilities* capabilities_ptr) {
    return functions->AddCapabilities(this, capabilities_ptr);
  }


  jvmtiError GetCapabilities(jvmtiCapabilities* capabilities_ptr) {
    return functions->GetCapabilities(this, capabilities_ptr);
  }

  

#endif /* __cplusplus */
};


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* !_JAVA_JVMTI_H_ */
