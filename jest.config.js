module.exports = {
	bail: false,
	collectCoverage: false,
	collectCoverageFrom: ["<rootDir>/packages/ledger-transport-ark/"],
	coverageDirectory: "<rootDir>/packages/ledger-transport-ark/.coverage",
	coverageReporters: ["json", "lcov", "text", "clover", "html"],
	globalSetup: "<rootDir>/__tests__/global-setup.ts",
	moduleFileExtensions: ["ts", "tsx", "js", "jsx", "json", "node"],
	modulePaths: [
		"<rootDir>"
	],
	setupFilesAfterEnv: ["jest-extended"],
	testEnvironment: "node",
	testMatch: ["<rootDir>/__tests__/*.test.tsx"],
	transform: {
		"^.+\\.tsx?$": "ts-jest",
	},
	verbose: false,
	globals: {
		"ts-jest": {
			packageJson: "./package.json",
		},
	},
};
