public class Suite {
	
	private long pointer; // Pointer to the coco_suite_t object
	private String name;

	/**
	 * Constructs the suite from the given suiteName, suiteInstance and suiteOptions.
	 * TODO: Copy explanation of options from the C code
	 * @param suiteName
	 * @param suiteInstance
	 * @param suiteOptions
	 * @throws Exception
	 */
	public Suite(String suiteName, String suiteInstance, String suiteOptions) throws Exception {

		super();
		try {
			this.pointer = CocoJNI.cocoGetSuite(suiteName, suiteInstance, suiteOptions);
			this.name = suiteName;
		} catch (Exception e) {
			throw new Exception("Suite constructor failed.\n" + e.toString());
		}
	}

	/**
	 * Finalizes the suite.
	 * @throws Exception 
	 */
	public void finalize() throws Exception {
		try {
			CocoJNI.cocoFinalizeSuite(this.pointer);
		} catch (Exception e) {
			throw new Exception("Suite finalization failed.\n" + e.toString());
		}
	}

	public long getPointer() {
		return this.pointer;
	}
	
	public String getName() {
		return this.name;
	}

	/* toString method */
	@Override
	public String toString() {
		return getName();
	}
}