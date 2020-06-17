package api

import (
	"errors"
)

var (
	ErrCompliationFail            = errors.New("compile fail")
	ErrRunFail                    = errors.New("run fail")
	ErrParseFail                  = errors.New("parse fail")
	ErrWriteBinaryFail            = errors.New("write binary fail")
	ErrResolvesNamesFail          = errors.New("resolve names fail")
	ErrValidateFail               = errors.New("validate fail")
	ErrSpanExceededCapacity       = errors.New("span exceeded capacity")
	ErrDeserializeFail            = errors.New("deserialize fail")
	ErrGasCounterInjectFail       = errors.New("gas counter inject fail")
	ErrSerializetFail             = errors.New("serialize fail")
	ErrUnknownError               = errors.New("unknown error")
	ErrCompliationError           = errors.New("compile fail")
	ErrRunError                   = errors.New("run fail")
	ErrParseError                 = errors.New("parse fail")
	ErrWriteBinaryError           = errors.New("write binary fail")
	ErrValidateError              = errors.New("validate fail")
	ErrGasLimitExceeded           = errors.New("gas limit exceeded")
	ErrNoMemoryWasm               = errors.New("no memory wasm")
	ErrMinimumMemoryExceed        = errors.New("minimum memory exceed")
	ErrSetMaximumMemory           = errors.New("maximum must be unset")
	ErrStackHeightInstrumentation = errors.New("stack height instrumention fail")
	ErrCheckWasmImports           = errors.New("check wasm imports fail")
	ErrCheckWasmExports           = errors.New("check wasm exports fail")
)

// parseError - returns parsed error from errors code on bindings.h
func parseError(code int32) error {
	switch code {
	case 0:
		return nil
	case 1:
		return ErrCompliationFail
	case 2:
		return ErrRunFail
	case 3:
		return ErrParseFail
	case 4:
		return ErrWriteBinaryFail
	case 5:
		return ErrResolvesNamesFail
	case 6:
		return ErrValidateFail
	case 7:
		return ErrSpanExceededCapacity
	case 8:
		return ErrDeserializeFail
	case 9:
		return ErrGasCounterInjectFail
	case 10:
		return ErrSerializetFail
	case 11:
		return ErrGasLimitExceeded
	case 12:
		return ErrNoMemoryWasm
	case 13:
		return ErrMinimumMemoryExceed
	case 14:
		return ErrSetMaximumMemory
	case 15:
		return ErrStackHeightInstrumentation
	case 16:
		return ErrCheckWasmImports
	case 17:
		return ErrCheckWasmExports
	default:
		return ErrUnknownError
	}

}
