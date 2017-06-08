/**
 * Struct that holds agent configuration
 */
#[derive(Debug, Copy, Clone)]
pub struct AgentParameters {
    pub time_threshold: usize,
    pub count_threshold: usize,
    pub print_heap_histogram: bool,
    pub heap_histogram_max_entries: usize,
    pub print_memory_usage: bool
}

impl AgentParameters {
    pub fn parseParameters(options: *const ::std::os::raw::c_char) -> Self {
        use std::ffi::CStr;

        let mut time_threshold: usize = 1;
        let mut count_threshold: usize = 0;
        let mut print_heap_histogram: usize = 0;
        let mut heap_histogram_max_entries: usize = 100;
        let mut print_memory_usage: usize = 1;

        let cslice;
        unsafe {
            cslice = CStr::from_ptr(options);
        }
        let s: &str = cslice.to_str().unwrap();
        let options = s.split(',').collect::<Vec<_>>();
        for option in &options {
            if option.is_empty() {
                continue
            }
            let tokens = option.splitn(2, '=').collect::<Vec<_>>();
            assert_eq!(tokens.len(), 2, "invalid option: {}", option);
            let key = tokens[0];
            let value = tokens[1];
            match key {
                "time" => if !value.is_empty() { time_threshold = value.parse().expect("not a number") },
                "count" => if !value.is_empty() { count_threshold = value.parse().expect("not a number") },
                "printHeapHistogram" => if !value.is_empty() { print_heap_histogram = value.parse().expect("not a number") },
                "heapHistogramMaxEntries" => if !value.is_empty() { heap_histogram_max_entries = value.parse().expect("not a number") },
                "printMemoryUsage" => if !value.is_empty() { print_memory_usage = value.parse().expect("not a number") },
                _ => assert!(false, "unknown option: {}", key),
            }
        }

        Self {
            time_threshold: time_threshold,
            count_threshold: count_threshold,
            print_heap_histogram: print_heap_histogram != 0,
            heap_histogram_max_entries: heap_histogram_max_entries,
            print_memory_usage: print_memory_usage != 0,
        }
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn defaults() {
        let ap = parse("");
        assert_eq!(ap.time_threshold, 1);
        assert_eq!(ap.count_threshold, 0);
        assert!(!ap.print_heap_histogram);
        assert_eq!(ap.heap_histogram_max_entries, 100);
        assert!(ap.print_memory_usage);
    }

    #[test]
    fn parses_time_threshold() {
        let ap = parse("time=99");
        assert_eq!(ap.time_threshold, 99);
    }

    #[test]
    fn parses_time_threshold_default() {
        let ap = parse("time=");
        assert_eq!(ap.time_threshold, 1);
    }

    #[test]
    #[should_panic(expected = "not a number")]
    fn parses_time_threshold_invalid() {
        let ap = parse("time=forever");
        assert_eq!(ap.time_threshold, 1);
    }

    #[test]
    fn parses_count_threshold() {
        let ap = parse("count=88");
        assert_eq!(ap.count_threshold, 88);
    }

    #[test]
    fn parses_count_threshold_default() {
        let ap = parse("count=");
        assert_eq!(ap.count_threshold, 0);
    }

    #[test]
    #[should_panic(expected = "not a number")]
    fn parses_count_threshold_invalid() {
        let ap = parse("count=zero");
        assert_eq!(ap.count_threshold, 0);
    }

    #[test]
    fn parses_print_heap_histogram_on() {
        let ap = parse("printHeapHistogram=1");
        assert!(ap.print_heap_histogram);
    }

    #[test]
    fn parses_print_heap_histogram_off() {
        let ap = parse("printHeapHistogram=0");
        assert!(!ap.print_heap_histogram);
    }

    #[test]
    fn parses_print_heap_histogram_default() {
        let ap = parse("printHeapHistogram=");
        assert!(!ap.print_heap_histogram);
    }

    #[test]
    #[should_panic(expected = "not a number")]
    fn parses_print_heap_histogram_invalid() {
        let ap = parse("printHeapHistogram=true");
        assert!(!ap.print_heap_histogram);
    }

    #[test]
    fn parses_heap_histogram_max_entries() {
        let ap = parse("heapHistogramMaxEntries=200");
        assert_eq!(ap.heap_histogram_max_entries, 200);
    }

    #[test]
    fn parses_heap_histogram_max_entries_unlimited() {
        let ap = parse("heapHistogramMaxEntries=0");
        assert_eq!(ap.heap_histogram_max_entries, 0);
    }

    #[test]
    fn parses_heap_histogram_max_entries_default() {
        let ap = parse("heapHistogramMaxEntries=");
        assert_eq!(ap.heap_histogram_max_entries, 100);
    }

    #[test]
    #[should_panic(expected = "not a number")]
    fn parses_heap_histogram_max_entries_invalid() {
        let ap = parse("heapHistogramMaxEntries=unlimited");
        assert_eq!(ap.heap_histogram_max_entries, 100);
    }

    #[test]
    fn parses_print_memory_usage_on() {
        let ap = parse("printMemoryUsage=1");
        assert!(ap.print_memory_usage);
    }

    #[test]
    fn parses_print_memory_usage_off() {
        let ap = parse("printMemoryUsage=0");
        assert!(!ap.print_memory_usage);
    }

    #[test]
    fn parses_print_memory_usage_default() {
        let ap = parse("printMemoryUsage=");
        assert!(ap.print_memory_usage);
    }

    #[test]
    #[should_panic(expected = "not a number")]
    fn parses_print_memory_usage_invalid() {
        let ap = parse("printMemoryUsage=false");
        assert!(ap.print_memory_usage);
    }

    #[test]
    #[should_panic(expected = "unknown option: noSuch")]
    fn unknown_option() {
        parse("noSuch=0");
    }

    #[test]
    #[should_panic(expected = "invalid option: noequals")]
    fn invalid_option() {
        parse("noequals");
    }

    fn parse(o: &str) -> super::AgentParameters {
        use std::ffi::CString;

        let cstr = CString::new(o).unwrap();
        super::AgentParameters::parseParameters(cstr.as_ptr())
    }
}
