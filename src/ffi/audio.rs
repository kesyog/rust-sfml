pub use crate::ffi::*;
use {
    super::system::sfInputStreamHelper,
    crate::cpp::{CppString as sfStdString, CppStringVector as sfStdStringVector},
};

decl_opaque! {
    pub(crate) sfSoundBufferRecorder;
    pub(crate) sfCustomSoundRecorder;
    pub(crate) sfMusic;
    pub(crate) sfSound;
    pub(crate) sfCustomSoundStream;
}

pub type sfSoundBuffer = crate::audio::SoundBuffer;

#[repr(C)]
pub struct sfSoundStreamChunk {
    pub samples: *const i16,
    pub sample_count: usize,
}

#[repr(C)]
#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord)]
pub enum sfSoundStatus {
    /// Sound is not playing
    Stopped,
    /// Sound is paused
    Paused,
    /// Sound is playing
    Playing,
}

type sfMusicStatus = sfSoundStatus;
type sfSoundStreamStatus = sfSoundStatus;

#[repr(C)]
pub struct sfTimeSpan {
    /// The beginning offset of the time range
    pub offset: i64,
    /// The length of the time range
    pub length: i64,
}

type sfCustomSoundRecorderStartCb = Option<unsafe extern "C" fn(user_data: *mut c_void) -> bool>;
type sfCustomSoundRecorderProcessCb =
    Option<unsafe extern "C" fn(samples: *const i16, len: usize, user_data: *mut c_void) -> bool>;
type sfCustomSoundRecorderStopCb = Option<unsafe extern "C" fn(user_data: *mut c_void)>;

type sfCustomSoundStreamGetDataCb =
    Option<unsafe extern "C" fn(chunk: *mut sfSoundStreamChunk, user_data: *mut c_void) -> bool>;
type sfCustomSoundStreamSeekCb = Option<unsafe extern "C" fn(pos: i64, user_data: *mut c_void)>;

include!("audio_bindgen.rs");
